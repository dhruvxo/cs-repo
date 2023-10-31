import numpy as np
import warnings
warnings.filterwarnings("ignore", category = RuntimeWarning)


class NaiveBayesClassifier:
    """
    A simple implementation of the Naive Bayes Classifier for text classification.
    This classifier assumes that the input features are binary word occurrences in documents.

    Attributes:
        None

    Methods:
        fit(X, y):
            Trains the Naive Bayes Classifier using the provided training data.
            
            Args:
                X (numpy.ndarray): The training data matrix where each row represents a document
                                  and each column represents the presence (1) or absence (0) of a word.
                y (numpy.ndarray): The corresponding labels for the training documents.

            Returns:
                tuple: A tuple containing two dictionaries:
                    - class_probs (dict): Prior probabilities of each class in the training set.
                    - word_probs (dict): Conditional probabilities of words given each class.

        predict(X, class_probs, word_probs, classes):
            Predicts the classes for the given test data using the trained classifier.

            Args:
                X (numpy.ndarray): The test data matrix where each row represents a document
                                  and each column represents the presence (1) or absence (0) of a word.
                class_probs (dict): Prior probabilities of each class obtained from the training phase.
                word_probs (dict): Conditional probabilities of words given each class obtained from training.
                classes (numpy.ndarray): The unique classes in the dataset.

            Returns:
                list: A list of predicted class labels for the test documents.

    Usage Example:
    The functions you write will be called as given below: 
    
        # Instantiate the classifier
        nb_classifier = NaiveBayesClassifier()

        # Train the classifier
        class_probs, word_probs = nb_classifier.fit(X_train, y_train)

        # Predict using the trained classifier
        predicted_labels = nb_classifier.predict(X_test, class_probs, word_probs, classes)

    Note: You do not have to call these functions. They will be called when you run the test_naive_bayes.py 
    """

    @staticmethod
    def fit(X, y):
        """
        Trains the Naive Bayes Classifier using the provided training data.
        
        Args:
            X (numpy.ndarray): The training data matrix where each row represents a document
                              and each column represents the presence (1) or absence (0) of a word.
            y (numpy.ndarray): The corresponding labels for the training documents.

        Returns:
            tuple: A tuple containing two dictionaries:
                - class_probs (dict): Prior probabilities of each class in the training set.
                - word_probs (dict): Conditional probabilities of words given each class.
        """
        classes = np.unique(y)
        class_probs = {}
        word_probs = {}
        total_documents = len(y)

        # Write your code here

        return class_probs, word_probs

    @staticmethod
    def predict(X, class_probs, word_probs, classes):
        """
        Predicts the classes for the given test data using the trained classifier.

        Args:
            X (numpy.ndarray): The test data matrix where each row represents a document
                              and each column represents the presence (1) or absence (0) of a word.
            class_probs (dict): Prior probabilities of each class obtained from the training phase.
            word_probs (dict): Conditional probabilities of words given each class obtained from training.
            classes (numpy.ndarray): The unique classes in the dataset.

        Returns:
            list: A list of predicted class labels for the test documents.
        """
        predictions = []
        
        # Write your code here 
        
        return predictions
