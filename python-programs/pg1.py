# Input data for three students and their scores in five subjects
students = {
    "Student 1": [85, 92, 78, 88, 90],
    "Student 2": [72, 65, 80, 76, 88],
    "Student 3": [90, 88, 92, 78, 85]
}

# Calculate and display average scores for each student
for student, scores in students.items():
    average_score = sum(scores) / len(scores)
    print(f"{student}: Average Score = {average_score}")