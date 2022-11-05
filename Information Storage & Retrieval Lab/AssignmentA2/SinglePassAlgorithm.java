import java.io.*;
import java.util.*;

class Document {
    String name;
    Map<String, Double> token;

    Document(String fileName) throws IOException {
        name = fileName;
        token = new HashMap<>();

        String pathName = "C:\\Users\\<YOUR_USER_NAME>\\Assignment\\" + fileName + ".txt";
        File myFile = new File(pathName);
        BufferedReader br = new BufferedReader(new FileReader(myFile));
        String st = br.readLine();

        while (st != null) {
            String[] words = st.split(" ");
            for (String word : words) {
                if (!token.containsKey(word)) {
                    token.put(word, (double) 0);
                }
                token.put(word, token.get(word) + 1);
            }
            st = br.readLine();
        }
    }
}

class Cluster {
    String name;
    Map<String, Double> centroid;
    List<Document> documentList = new ArrayList<>();

    Cluster(String name, Document document) {
        this.name = name;
        this.centroid = document.token;
        documentList.add(document);
    }

    public void updateClusterCentroid(Document document) {
        Map<String, Double> documentCentroid = document.token;

        for (String word : centroid.keySet()) {
            double x = centroid.get(word);
            if (documentCentroid.containsKey(word)) {
                double y = documentCentroid.get(word);
                centroid.put(word, (x + y) / 2);
            } else {
                centroid.put(word, x / 2);
            }
        }
    }
}

public class SinglePassAlgorithm {
    static List<Cluster> clusterList = new ArrayList<>();
    static int threshold = 10;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        System.out.println("Single-pass Algorithm for clustering of files\n");
        System.out.println("Select an option");
        System.out.println("1) Cluster overlapping");
        System.out.println("2) Cluster disjoint");
        int option = sc.nextInt();
        System.out.println();

        if (option == 1) {
            overlapping();
        } else if (option == 2) {
            disjoint();
        } else {
            System.out.println("Invalid Input");
        }
    }

    public static void overlapping() throws IOException {
        Document document1 = new Document("d1");
        Document document2 = new Document("d2");
        Document document3 = new Document("d3");
        Document document4 = new Document("d4");
        Document document5 = new Document("d5");

        createNewCluster(document1);

        addDocumentToCluster(document2, "overlapping");
        addDocumentToCluster(document3, "overlapping");
        addDocumentToCluster(document4, "overlapping");
        addDocumentToCluster(document5, "overlapping");

        printClusters();
    }

    public static void disjoint() throws IOException {
        Document document1 = new Document("d1");
        Document document2 = new Document("d2");
        Document document3 = new Document("d3");
        Document document4 = new Document("d4");
        Document document5 = new Document("d5");

        createNewCluster(document1);

        addDocumentToCluster(document2, "disjoint");
        addDocumentToCluster(document3, "disjoint");
        addDocumentToCluster(document4, "disjoint");
        addDocumentToCluster(document5, "disjoint");

        printClusters();
    }

    private static void createNewCluster(Document document) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter new cluster name: ");
        String name = sc.next();
        clusterList.add(new Cluster(name, document));
    }

    private static void addDocumentToCluster(Document document, String mode) {
        double max = Integer.MIN_VALUE;
        int pos = -1;
        for (int i = 0; i < clusterList.size(); i++) {
            double temp = getSimilarity(clusterList.get(i).centroid, document.token);
            if (temp > max) {
                max = temp;
                pos = i;
            }
            if (mode.equals("overlapping") && temp >= threshold) {
                clusterList.get(i).documentList.add(document);
                clusterList.get(i).updateClusterCentroid(document);
            }
        }

        if (mode.equals("disjoint") && max >= threshold) {
            clusterList.get(pos).documentList.add(document);
            clusterList.get(pos).updateClusterCentroid(document);
        } else if (max < threshold) {
            createNewCluster(document);
        }
    }

    private static double getSimilarity(Map<String, Double> clusterCentroid, Map<String, Double> documentCentroid) {
        double similarity = 0;
        for (String word : clusterCentroid.keySet()) {
            if (documentCentroid.containsKey(word)) {
                similarity += (documentCentroid.get(word) * clusterCentroid.get(word));
            }
        }
        return similarity;
    }

    private static void printClusters() {
        for (Cluster cluster : clusterList) {
            System.out.print(cluster.name + " -> ");
            for (Document document : cluster.documentList) {
                System.out.print(document.name + " ");
            }
            System.out.println();
        }
    }
}
