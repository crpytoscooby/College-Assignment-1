import java.util.*;

public class ISR_AssignmentB1 {

    public static void main(String[] args) {
        String[] relevantDocumentArr = {"d3", "d5", "d9", "d25", "d39", "d44", "d56", "d71", "d89", "d123"};
        Set<String> relevantDocument = new HashSet<>();
        for (String doc : relevantDocumentArr) {
            relevantDocument.add(doc);
        }
        int relevantSize = relevantDocument.size();

        String[] retrievedDocumentArr = {"d123", "d84", "d56", "d6", "d8", "d9", "d511", "d129", "d187", "d25", "d38", "d48", "d250", "d113", "d3"};
        int retrievedSize = retrievedDocumentArr.length;

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
            precision *= 100;
            double recall = (double) count / relevantSize;
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
*/
