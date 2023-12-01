import turtle

def draw_sierpinski(length, depth):

    if depth == 0:
        for _ in range(3):
            turtle.forward(length)
            turtle.right(120)
    else:
        draw_sierpinski(length / 2, depth - 1)
        turtle.forward(length / 2)
        draw_sierpinski(length / 2, depth - 1)
        turtle.backward(length / 2)
        turtle.right(60)
        turtle.forward(length / 2)
        turtle.left(60)
        draw_sierpinski(length / 2, depth - 1)
        turtle.right(60)
        turtle.backward(length / 2)
        turtle.left(60)

# Set the speed of the drawing
turtle.speed(0)

# Draw a Sierpinski Gasket with side length 200 and depth 4
draw_sierpinski(200, 4)

# Hide the turtle cursor
turtle.hideturtle()

# Keep the window open
turtle.done()

