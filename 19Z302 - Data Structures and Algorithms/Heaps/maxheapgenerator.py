import random

def generate_random_max_heap(n):
  """Generates a random max heap of size n.

  Args:
    n: The size of the heap.

  Returns:
    A list representing the random max heap.
  """

  heap = []
  for i in range(n):
    heap.append(random.randint(0, 100))

  for i in range(n // 2 - 1, -1, -1):
    heapify(heap, i)

  return heap

def heapify(heap, i):
  """Heapifies the heap at index i.

  Args:
    heap: The heap to heapify.
    i: The index of the heap to heapify.
  """

  largest = i
  left = 2 * i + 1
  right = 2 * i + 2

  if left < len(heap) and heap[left] > heap[largest]:
    largest = left

  if right < len(heap) and heap[right] > heap[largest]:
    largest = right

  if largest != i:
    heap[i], heap[largest] = heap[largest], heap[i]
    heapify(heap, largest)

if __name__ == '__main__':
  heap = generate_random_max_heap(10)
  print(heap)