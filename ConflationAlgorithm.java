import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.*;

public class ConflationAlgorithm {

    static class Pair {
        String word;
        int count;

        Pair(String word, int count) {
            this.word = word;
            this.count = count;
        }
    }

    public static void removeStopWords(Map<String, Integer> map) throws Exception {
        File myFile = new File("C:\\Users\\Denzil\\IdeaProjects\\Assignment\\src\\stopwords.txt");
        BufferedReader br = new BufferedReader(new FileReader(myFile));
        String st = br.readLine();
        while (st != null) {
            map.remove(st);
            st = br.readLine();
        }
    }

    public static void countWords(String text, Map<String, Integer> map) {
        String tempText = text.toLowerCase();
        String[] skips = {".", ",", ":", ";", "'", "\"", "-"};
        for (String c : skips) {
            if (c.equals("-")) {
                tempText = tempText.replace(c, " ");
            } else {
                tempText = tempText.replace(c, "");
            }
        }
        for (String word : tempText.split(" ")) {
            String newWord = porterAlgo(word);
            if (!map.containsKey(newWord)) {
                map.put(newWord, 0);
            }
            map.put(newWord, map.get(newWord) + 1);
        }
    }

    public static String porterAlgo(String word) {
        StringBuilder sb = new StringBuilder();
        if (word.endsWith("ed") || word.endsWith("ly")) {
            sb.append(word, 0, word.length() - 2);
        } else if (word.endsWith("ing") || word.endsWith("ful")) {
            sb.append(word, 0, word.length() - 3);
        } else if (word.endsWith("ness")) {
            sb.append(word, 0, word.length() - 4);
        } else {
            sb.append(word);
        }
        return sb.toString();
    }

    public static void main(String[] args) throws Exception {
        File input = new File("C:\\Users\\Denzil\\IdeaProjects\\Assignment\\src\\Input.txt");
        BufferedReader br = new BufferedReader(new FileReader(input));
        StringBuilder sb = new StringBuilder();
        String st = br.readLine();

        while (st != null) {
            sb.append(st);
            st = br.readLine();
        }

        String text = sb.toString();

        Map<String, Integer> map = new HashMap<>();
        countWords(text, map);
        removeStopWords(map);

        // max heap
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> (b.count - a.count));
        for (String key : map.keySet()) {
            if (map.get(key) >= 2) {
                pq.add(new Pair(key, map.get(key)));
            }
        }

        for (Pair p : pq) {
            System.out.println(p.word + " : " + p.count);
        }
    }
}
