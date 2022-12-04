class Solution {
    double r, x, y;
    Random random = new Random();
    public Solution(double _r, double _x, double _y) {
        r = _r; x = _x; y = _y;
    }
    public double[] randPoint() {
        double len = Math.sqrt(random.nextDouble(r * r)), ang = random.nextDouble(2 * Math.PI);
        double nx = x + len * Math.cos(ang), ny = y + len * Math.sin(ang);
        return new double[]{nx, ny};
    }
}
