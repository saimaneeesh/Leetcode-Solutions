class Solution {
    public String solveEquation(String equation) {
        String[] sides = equation.split("=");
        int[] left = parseSide(sides[0]);
        int[] right = parseSide(sides[1]);
        
        int xCoeff = left[0] - right[0];
        int constant = right[1] - left[1];
        
        if (xCoeff == 0) {
            if (constant == 0) return "Infinite solutions";
            else return "No solution";
        }
        
        return "x=" + (constant / xCoeff);
    }
    
    private int[] parseSide(String expr) {
        expr = expr.replace("-", "+-");
        String[] terms = expr.split("\\+");
        int xCoeff = 0;
        int constant = 0;
        
        for (String term : terms) {
            if (term.isEmpty()) continue;
            if (term.contains("x")) {
                String coeff = term.replace("x", "");
                if (coeff.equals("") || coeff.equals("+")) coeff = "1";
                else if (coeff.equals("-")) coeff = "-1";
                xCoeff += Integer.parseInt(coeff);
            } else {
                constant += Integer.parseInt(term);
            }
        }
        return new int[]{xCoeff, constant};
    }
}