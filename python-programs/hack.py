import pandas as pd
import torch

train = pd.read_csv('/kaggle/input/pesurrcampusmihackathoncompetitiona/train.csv')
test = pd.read_csv('/kaggle/input/pesurrcampusmihackathoncompetitiona/test.csv')

import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, LabelEncoder
from sklearn.metrics import accuracy_score
import tensorflow as tf
from tensorflow import keras

# Data preprocessing
X_train = train.drop(['filename', 'label'], axis=1)
y_train = train['label']
X_test = test.drop('id', axis=1)

# Standardize the features
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# Encode genre labels
label_encoder = LabelEncoder()
y_train_encoded = label_encoder.fit_transform(y_train)

# Split the training data into train and validation sets
X_train, X_val, y_train, y_val = train_test_split(X_train, y_train_encoded, test_size=0.2, random_state=42)

# Create an Artificial Neural Network (ANN) model using Keras
model = keras.Sequential([
    keras.layers.Input(shape=(X_train.shape[1],)),  # Input layer
    keras.layers.Dense(128, activation='relu'),     # Hidden layer
    keras.layers.Dense(64, activation='relu'),      # Hidden layer
    keras.layers.Dense(len(np.unique(y_train)), activation='softmax')  # Output layer
])

# Compile the model
model.compile(optimizer='adam',loss='sparse_categorical_crossentropy',metrics=['accuracy'])

# Train the model
model.fit(X_train, y_train, epochs=50, batch_size=32, validation_data=(X_val, y_val))

# Make predictions on the test set
test_predictions = model.predict(X_test)
test_predictions = np.argmax(test_predictions, axis=1)

# Reverse label encoding
test_predictions = label_encoder.inverse_transform(test_predictions)

# Evaluate the model on the validation set
val_accuracy = model.evaluate(X_val, y_val, verbose=0)[1]
print(f'Validation Accuracy: {val_accuracy * 100:.2f}%')
label_encoder = LabelEncoder()
y = label_encoder.fit_transform(test_predictions)
data = pd.DataFrame({'id': test['id'], 'label': y})
data.to_csv('music_gen_predicts.csv',index=False)