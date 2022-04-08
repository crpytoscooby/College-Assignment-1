// WCMap.java

package com;

import java.io.IOException;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class WCMap extends Mapper<LongWritable, Text, Text, IntWritable> {
	
	public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
		String[] row = value.toString().split(",");

		String ipAddress = row[0];
		
		if (isValidIP(ipAddress)) {
			context.write(new Text(ipAddress), new IntWritable(1));
		}
	}
	
	// This function will check if the inputed string contains numeric values and a '.'
	public static boolean isValidIP(String ipAddress) {		
		for (int i = 0; i < ipAddress.length(); i++) {
			char c = ipAddress.charAt(i);
			if (((int) c >= 48 && (int) c <= 57) || c == '.') {
				continue;
			} else {
				return false;
			}
		}
		return true;
	}
}
