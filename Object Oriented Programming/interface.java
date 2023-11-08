// interface example

interface ShapeEdge {
    public int getEdges();
}

interface ShapeVetex{
    public int getVertices();
}

interface IShape extends ShapeEdge,ShapeVetex {
    public double getArea();
    public double getPerimeter();
}

class Rectangle implements IShape {
    private double length;
    private double width;
    private int edges;
    private int vertices;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
        this.edges = 4;
        this.vertices = 4;
    }

    public double getArea(){
        return 2 * (length + width);
    }

    public double getPerimeter(){
        return length * width;
    }

    public int getEdges(){
        return edges;
    }

    public int getVertices(){
        return vertices;
    }
}