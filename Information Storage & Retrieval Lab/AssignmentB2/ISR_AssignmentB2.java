import java.util.*;

public class ISR_AssignmentB2 {

    public static void main(String[] args) {

        String[] relevantDocumentArr = {"d3", "d5", "d9", "d25", "d39", "d44", "d56", "d71", "d89", "d123"};
        Set<String> relevantDocument = new HashSet<>();
        for (String doc : relevantDocumentArr) {
            relevantDocument.add(doc);
        }
        int relevantSize = relevantDocument.size();

        String[] retrievedDocumentArr = {"d123", "d84", "d56", "d6", "d8", "d9", "d511", "d129", "d187", "d25", "d38", "d48", "d250", "d113", "d3"};
        int retrievedSize = retrievedDocumentArr.length;

        double[] fMeasure = new double[retrievedSize];
        double[][] eMeasures = new double[retrievedSize][3];    // b < 1, b == 1, b > 1

        System.out.println("-----------------------------------------------------------------------------------------------");
        System.out.println("Input\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  | Precision \t|   Recall");
        System.out.println("-----------------------------------------------------------------------------------------------");

        int count = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < retrievedSize; i++) {
            if (relevantDocument.contains(retrievedDocumentArr[i])) {
                count++;
            }
            double precision = (double) count / (i + 1);
            double recall = (double) count / relevantSize;

            // Calculating F-Measure
            fMeasure[i] = 2 / ((1 / recall) + (1 / precision));

            double b = 0.9;
            eMeasures[i][0] = getEMeasure(precision, recall, b);
            b = 0;
            eMeasures[i][1] = getEMeasure(precision, recall, b);
            b = 1.1;
            eMeasures[i][2] = getEMeasure(precision, recall, b);


            precision *= 100;
            recall *= 100;

            sb.append(retrievedDocumentArr[i]);
            sb.append(" ");
            System.out.print(sb);
            for (int tabs = sb.length(); tabs < 70; tabs++) {
                System.out.print(" ");
            }
            System.out.println("|\t" + String.format("%.2f", precision) + "%\t\t|\t" + String.format("%.2f", recall) + "%");
        }
        System.out.println("-----------------------------------------------------------------------------------------------");


        Scanner sc = new Scanner(System.in);
        System.out.println("Harmonic mean and E-value");
        System.out.print("Enter value of j(0 - " + (retrievedSize - 1) + ") to find F(j) and E(j): ");
        int efIndex = sc.nextInt();
        System.out.println();

        System.out.println("Harmonic Mean (F1) is : " + String.format("%.2f", fMeasure[efIndex]));

        System.out.println("E-Value: ");
        System.out.println("b > 1 | b = 0 | b < 1");
        System.out.println(String.format("%.2f", eMeasures[efIndex][2]) + " |  " + String.format("%.2f", eMeasures[efIndex][1]) + " |  " + String.format("%.2f", eMeasures[efIndex][0]));
        sc.close();
    }

    private static double getEMeasure(double precision, double recall, double b) {
        double bSquare = Math.pow(b, 2);
        return 1 - ((1 + bSquare) / ((bSquare / recall) + (1 / precision)));
    }
}

/* Output
-----------------------------------------------------------------------------------------------
Input																  | Precision 	|   Recall
-----------------------------------------------------------------------------------------------
d123                                                                  |	100.00%		|	10.00%
d123 d84                                                              |	50.00%		|	10.00%
d123 d84 d56                                                          |	66.67%		|	20.00%
d123 d84 d56 d6                                                       |	50.00%		|	20.00%
d123 d84 d56 d6 d8                                                    |	40.00%		|	20.00%
d123 d84 d56 d6 d8 d9                                                 |	50.00%		|	30.00%
d123 d84 d56 d6 d8 d9 d511                                            |	42.86%		|	30.00%
d123 d84 d56 d6 d8 d9 d511 d129                                       |	37.50%		|	30.00%
d123 d84 d56 d6 d8 d9 d511 d129 d187                                  |	33.33%		|	30.00%
d123 d84 d56 d6 d8 d9 d511 d129 d187 d25                              |	40.00%		|	40.00%
d123 d84 d56 d6 d8 d9 d511 d129 d187 d25 d38                          |	36.36%		|	40.00%
d123 d84 d56 d6 d8 d9 d511 d129 d187 d25 d38 d48                      |	33.33%		|	40.00%
d123 d84 d56 d6 d8 d9 d511 d129 d187 d25 d38 d48 d250                 |	30.77%		|	40.00%
d123 d84 d56 d6 d8 d9 d511 d129 d187 d25 d38 d48 d250 d113            |	28.57%		|	40.00%
d123 d84 d56 d6 d8 d9 d511 d129 d187 d25 d38 d48 d250 d113 d3         |	33.33%		|	50.00%
-----------------------------------------------------------------------------------------------
Harmonic mean and E-value
Enter value of j(0 - 14) to find F(j) and E(j): 5

Harmonic Mean (F1) is : 0.37
E-Value:
b > 1 | b = 0 | b < 1
0.63 |  0.50 |  0.61
*/
