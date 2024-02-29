def quick_hull(points):
    if len(points) < 3:
        return points

    def distance(p1, p2, p):
        returndistance = (p2[0] - p1[0]) * (p[1] - p1[1]) - (p2[1] - p1[1]) * (p[0] - p1[0])
        print(f"Distance between {p1} , {p2} and {p} is {returndistance} ")
        return returndistance

    def find_hull(p1, p2, points):
        if not points:
            return []

        max_dist = 0
        max_point = None

        for point in points:
            dist = distance(p1, p2, point)
            if dist > max_dist:
                max_dist = dist
                max_point = point

        points.remove(max_point)

        left = [point for point in points if distance(p1, max_point, point) > 0]
        right = [point for point in points if distance(max_point, p2, point) > 0]

        print(f"For {p1} and {p2} the max point is {max_point} and the left and right points are {left} and {right}")

        return find_hull(p1, max_point, left) + [max_point] + find_hull(max_point, p2, right)

    min_x = min(points, key=lambda p: p[0])
    max_x = max(points, key=lambda p: p[0])

    upper_hull = find_hull(min_x, max_x, points)
    lower_hull = find_hull(max_x, min_x, points)

    return upper_hull + lower_hull

# Generate a list of 10 random points
points = [(0,0), (1,5), (2, 10), (3, 2), (4, 7), (6, 1), (7, 4), (10, 4)]
print(points)
# Use the quick_hull function to find the convex hull of the points
hull = quick_hull(points)

# Print the points in the convex hull
for point in hull:
    print(point)