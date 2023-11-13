public class experiment9a {
    public static void main(String[] args) {
        Cars Volkswagen = new Volkswagen(5.0);
        Cars Implementation2 = new Implementation2(4.0, 3.0);

        System.out.println("Volkswagen area: " + Volkswagen.ManufacturerInformation());
        System.out.println("Implementation2 area: " + Implementation2.ManufacturerInformation());
    }
}

interface Cars {
    double ManufacturerInformation();
}

class Volkswagen implements Cars {
    private double groundclearance;

    public Volkswagen(double groundclearance) {
        this.groundclearance = groundclearance;
    }

    @Override
    public String ManufacturerInformation() {
        return "Germany";
    }
}

class BritishMotorWorks implements Cars {
    private double groundclearance;

    public BritishMotorWorks(double groundclearance) {
        this.groundclearance = groundclearance;
    }

    @Override
    public String ManufacturerInformation() {
        return "England";
    }
}
