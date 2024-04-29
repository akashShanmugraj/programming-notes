import threading
import time
import random


class Child(threading.Thread):
    def __init__(self, name, caregiver_semaphore, child_semaphore):
        super().__init__()
        self.name = name
        self.caregiver_semaphore = caregiver_semaphore
        self.child_semaphore = child_semaphore

    def run(self):
        print(f"Child {self.name} needs care.")
        self.caregiver_semaphore.acquire()  # Wait for caregiver to have capacity
        print(f"Child {self.name} is receiving care.")
        time.sleep(random.uniform(1, 3))  # Simulate care
        self.child_semaphore.release()  # Signal that care is done
        self.caregiver_semaphore.release()  # Release caregiver's capacity


class Caregiver(threading.Thread):
    def __init__(self, caregiver_semaphore, child_semaphore, capacity):
        super().__init__()
        self.caregiver_semaphore = caregiver_semaphore
        self.child_semaphore = child_semaphore
        self.capacity = capacity

    def run(self):
        while True:
            self.caregiver_semaphore.acquire()  # Wait for a child to arrive
            print("Caregiver is available.")
            self.child_semaphore.acquire()  # Wait for child to signal care is done
            print("Caregiver is caring for a child.")
            time.sleep(random.uniform(1, 3))  # Simulate care
            print("Caregiver has finished caring for a child.")


def main():
    caregiver_semaphore = threading.Semaphore(
        1
    )  # Semaphore for caregiver capacity (1 for single caregiver)
    child_semaphore = threading.Semaphore(
        0
    )  # Semaphore for child signaling care is done

    caregiver = Caregiver(caregiver_semaphore, child_semaphore, capacity=3)
    caregiver.start()

    children = []
    for i in range(5):
        child = Child(
            name=i,
            caregiver_semaphore=caregiver_semaphore,
            child_semaphore=child_semaphore,
        )
        children.append(child)
        child.start()

    for child in children:
        child.join()
    caregiver.join()


if __name__ == "__main__":
    main()
