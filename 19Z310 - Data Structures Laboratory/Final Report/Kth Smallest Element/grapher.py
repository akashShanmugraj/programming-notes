import pandas as pd

import matplotlib.pyplot as plt


# Read the CSV file into a Pandas DataFrame
df = pd.read_csv('./benchmarks.csv')
plt.figure(figsize=(8, 6))
plt.scatter(df['Array Size'], df['Runtime'], alpha=0.5)
plt.xlabel('Array Size')
plt.ylabel('Runtime (seconds)')
plt.title('Runtime vs Array Size')
plt.grid(True)
plt.show()

avg_runtime = df.groupby('Array Size')['Runtime'].mean().reset_index()

# Create a line graph for Array Size vs Average Runtime
plt.figure(figsize=(10, 6))
plt.plot(avg_runtime['Array Size'], avg_runtime['Runtime'], marker='o', linestyle='-', color='b')
plt.xlabel('Array Size')
plt.ylabel('Average Runtime (seconds)')
plt.title('Average Runtime vs Array Size')
plt.grid(True)
plt.show()

# Calculate and display the overall average runtime
overall_avg_runtime = df['Runtime'].mean()
print(f"Overall Average Runtime: {overall_avg_runtime:.6f} seconds")
# Create a bar graph for Array Size vs Average Runtime
plt.figure(figsize=(10, 6))
plt.bar(avg_runtime['Array Size'], avg_runtime['Runtime'], color='b')
plt.xlabel('Array Size')
plt.ylabel('Average Runtime (seconds)')
plt.title('Average Runtime vs Array Size')
plt.grid(True)
plt.show()

# Calculate and display the overall average runtime
overall_avg_runtime = df['Runtime'].mean()
print(f"Overall Average Runtime: {overall_avg_runtime:.6f} seconds")