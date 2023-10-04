import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, confusion_matrix

# Split the data into training and testing sets
# input: 1) x: list/ndarray (features)
#        2) y: list/ndarray (target)
# output: split: tuple of X_train, X_test, y_train, y_test
def split_and_standardize(X, y):
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    # Standardize the features using StandardScaler
    scaler = StandardScaler()
    X_train = scaler.fit_transform(X_train)
    X_test = scaler.transform(X_test)

    return X_train, X_test, y_train, y_test

# Create and train 2 MLP classifiers (each with 3 hidden layers) with different parameters
# input:  1) X_train: list/ndarray
#         2) y_train: list/ndarray
# output: 1) models: model1, model2 - tuple
def create_model(X_train, y_train):
    model1 = MLPClassifier(hidden_layer_sizes=(20,10,30), activation='tanh', max_iter=100)
    model1.fit(X_train, y_train)


    model2 = MLPClassifier(hidden_layer_sizes=(30,20,10), activation='identity', max_iter=10, random_state=42)
    model2.fit(X_train, y_train)
    

    return (model1, model2)


# Predict using the trained model and evaluate performance
# input  : 1) model: MLPClassifier after training
#          2) X_test: list/ndarray
#          3) y_test: list/ndarray
# output : 1) metrics: tuple - accuracy, precision, recall, fscore, confusion matrix
def predict_and_evaluate(model, X_test, y_test):
    
    y_pred = model.predict(X_test)
    accuracy = accuracy_score(y_test, y_pred)
    precision = precision_score(y_test, y_pred,average='micro')
    recall = recall_score(y_test, y_pred,average='micro')
    fscore = f1_score(y_test, y_pred,average='micro')
    cm = confusion_matrix(y_test, y_pred)

    # print(accuracy, precision, recall, fscore, cm)

    return accuracy, precision, recall, fscore, cm