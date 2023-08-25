import torch
import math

def calculate_entropy(probabilities):
    entropy = 0
    for prob in probabilities:
        if prob > 0:
            entropy -= prob * math.log2(prob)
    return entropy

def get_entropy_of_dataset(data_tensor: torch.Tensor):
    target_column = data_tensor[:, -1]
    unique_values, counts = target_column.unique(return_counts=True)
    probabilities = counts / len(target_column)
    entropy = calculate_entropy(probabilities)
    return entropy

def get_avg_info_of_attribute(data_tensor: torch.Tensor, attribute_index: int):
    attribute_column = data_tensor[:, attribute_index]
    unique_values, counts = attribute_column.unique(return_counts=True)
    avg_info = 0
    total_samples = len(attribute_column)
    
    for value, count in zip(unique_values, counts):
        subset = data_tensor[attribute_column == value]
        subset_entropy = get_entropy_of_dataset(subset)
        avg_info += (count / total_samples) * subset_entropy
    
    return avg_info

def get_information_gain(data_tensor: torch.Tensor, attribute_index: int):
    dataset_entropy = get_entropy_of_dataset(data_tensor)
    attribute_avg_info = get_avg_info_of_attribute(data_tensor, attribute_index)
    information_gain = dataset_entropy - attribute_avg_info
    return information_gain

def get_selected_attribute(data_tensor: torch.Tensor):
    num_attributes = data_tensor.shape[1] - 1
    attribute_information_gains = {}
    
    for attribute in range(num_attributes):
        information_gain = get_information_gain(data_tensor, attribute)
        attribute_information_gains[attribute] = information_gain
        
    selected_attribute = max(attribute_information_gains, key=attribute_information_gains.get)
    return attribute_information_gains, selected_attribute
