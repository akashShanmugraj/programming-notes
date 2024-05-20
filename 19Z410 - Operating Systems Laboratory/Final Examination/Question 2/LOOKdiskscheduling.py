def sort_requests(arr):
    # Sort the array of requests in ascending order
    return sorted(arr)

def find_next_nearest(arr, head, direction):
    # Find the next nearest request from the current head position based on the direction
    next_nearest = -1
    
    if direction == 1:
        # Moving towards higher track numbers
        for track in arr:
            if track >= head:
                next_nearest = track
                break
    else:
        # Moving towards lower track numbers
        for track in reversed(arr):
            if track <= head:
                next_nearest = track
                break
    
    return next_nearest

def calculate_seek_time(arr, initial_head):
    head = initial_head
    total_seek_time = 0
    direction = 1  # Initial direction: moving towards higher track numbers
    
    # Sort the array of requests
    arr = sort_requests(arr)
    
    # Service requests until all requests are processed
    while True:
        next_nearest = find_next_nearest(arr, head, direction)
        
        if next_nearest == -1:
            # No more requests in the current direction, change direction
            direction = 1 - direction
            continue
        
        # Calculate seek time and update head position
        total_seek_time += abs(next_nearest - head)
        head = next_nearest
        print(f"Serviced request at track {head}")
        
        # Remove serviced request from array (not necessary for LOOK algorithm)
        
        # Check if all requests are serviced
        if all(track == -1 for track in arr):
            break
    
    return total_seek_time

# Example usage
initial_head = 50
requests = [10, 22, 20, 40, 35, 60, 80, 90]

total_seek_time = calculate_seek_time(requests, initial_head)
print(f"Total seek time: {total_seek_time}")
