import java.util.*;
import java.io.*;

class Document {
    String name;
    Map<String, List<Integer>> token;

    Document(String fileName) throws Exception {
        name = fileName;
        token = new HashMap<>();

        // location	C:\Users\HP\eclipse-workspace\ASSIGNMNET3\src\IndexedFile.java
        String pathName = "C:\\Users\\HP\\eclipse-workspace\\ASSIGNMNET3\\src\\" + fileName + ".txt";
        File myFile = new File(pathName);
        BufferedReader br = new BufferedReader(new FileReader(myFile));
        String st = br.readLine();

        StringBuilder sb = new StringBuilder();
        while (st != null) {
            sb.append(st);
            st = br.readLine();
        }

        String text = removeSpecialChars(sb.toString());
        int index = 0;
        for (String word : text.split(" ")) {
            if (!token.containsKey(word)) {
                token.put(word, new ArrayList<>());
            }
            List<Integer> list = token.get(word);
            list.add(index);
            token.put(word, list);
            index++;
        }
        removeStopWords(token);
    }

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

    public void removeStopWords(Map<String, List<Integer>> token2) throws Exception {
        File myFile = new File("C:\\Users\\HP\\eclipse-workspace\\ASSIGNMNET3\\src\\stopwords.txt");
        BufferedReader br = new BufferedReader(new FileReader(myFile));
        String st = br.readLine();
        while (st != null) {
            token2.remove(st);
            st = br.readLine();
        }
    }
}

public class IndexedFile {

    static Map<String, List<Integer>> indexedFileTable;

    public static void main(String[] args) throws Exception {
        indexedFileTable = new HashMap<>();
        generateIndexedFile();
        
        File indexes = new File("C:\\Users\\HP\\eclipse-workspace\\ASSIGNMNET3\\src\\indexes.txt");
        BufferedWriter bw = new BufferedWriter(new FileWriter(indexes));

        for (String key : indexedFileTable.keySet()) {
            String text = key + " : " + indexedFileTable.get(key);
            bw.write(text);
            bw.write("\n");
        }
        bw.close();

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Word to be Searched: ");
        String word = sc.next();
        if (indexedFileTable.containsKey(word)) {
            for (int index : indexedFileTable.get(word)) {
                System.out.println("The word " + word + " is present at position : " + index);
            }
        } else {
            System.out.println("Word not found");
        }
        sc.close();
    }

    public static void generateIndexedFile() throws Exception {
        Document document1 = new Document("d1");
        insertInTable(document1.token);
    }

    public static void insertInTable(Map<String, List<Integer>> map) {
        for (String key : map.keySet()) {
            if (!indexedFileTable.containsKey(key)) {
                indexedFileTable.put(key, new ArrayList<>());
            }
            indexedFileTable.put(key, map.get(key));
        }
    }
}
