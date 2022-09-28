import java.util.*;
import java.io.*;

class Document {
    String name;
    Set<String> token;

    Document(String fileName) throws Exception {
        name = fileName;
        token = new HashSet<>();

        String pathName = "C:\\Users\\Denzil\\IdeaProjects\\Assignment\\src\\InputFolder\\" + fileName + ".txt";
        File myFile = new File(pathName);
        BufferedReader br = new BufferedReader(new FileReader(myFile));
        String st = br.readLine();

        StringBuilder sb = new StringBuilder();
        while (st != null) {
            sb.append(st);
            st = br.readLine();
        }

        String text = removeSpecialChars(sb.toString());
        for (String word : text.split(" ")) {
            token.add(word);
        }
        removeStopWords(token);
    }

    // same as assignment 1 conflation algorithm
    public String removeSpecialChars(String text) {
        String tempText = text.toLowerCase();
        String[] skips = {".", ",", ":", ";", "'", "\"", "-"};
        for (String c : skips) {
            if (c.equals("-")) {
                tempText = tempText.replace(c, " ");
            } else {
                tempText = tempText.replace(c, "");
            }
        }
        return tempText;
    }

    // same as assignment 1 conflation algorithm
    public void removeStopWords(Set<String> token) throws Exception {
        File myFile = new File("C:\\Users\\Denzil\\IdeaProjects\\Assignment\\src\\stopwords.txt");
        BufferedReader br = new BufferedReader(new FileReader(myFile));
        String st = br.readLine();
        while (st != null) {
            token.remove(st);
            st = br.readLine();
        }
    }
}

public class IndexedFile {

    static TreeMap<String, List<Document>> indexedFileTable;

    public static void main(String[] args) throws Exception {
        indexedFileTable = new TreeMap<>();
        generateIndexedFile();
        displayIndexedFile();
    }

    public static void generateIndexedFile() throws Exception {
        Document document1 = new Document("d1");
        insertInTable(document1);
        Document document2 = new Document("d2");
        insertInTable(document2);
        Document document3 = new Document("d3");
        insertInTable(document3);
        Document document4 = new Document("d4");
        insertInTable(document4);
    }

    public static void displayIndexedFile() {
        for (String key : indexedFileTable.keySet()) {
            System.out.print(key + " : ");
            for (Document document : indexedFileTable.get(key)) {
                System.out.print(document.name + " ");
            }
            System.out.println();
        }
    }

    private static void insertInTable(Document document) {
        Set<String> set = document.token;
        for (String word : set) {
            if (!indexedFileTable.containsKey(word)) {
                indexedFileTable.put(word, new ArrayList<>());
            }
            List<Document> documentList = indexedFileTable.get(word);
            documentList.add(document);
            indexedFileTable.put(word, documentList);
        }
    }
}
