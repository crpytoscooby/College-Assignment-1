// WCDriver.java

package com;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FSDataInputStream;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class WCDriver {
	
	public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
		Configuration config = new Configuration();
		Job job = Job.getInstance(config, "word count");
		job.setJarByClass(com.WCDriver.class);
		job.setMapperClass(com.WCMap.class);
		job.setReducerClass(com.WCReduce.class);
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(IntWritable.class);
		FileInputFormat.addInputPath(job, new Path(args[0]));
		FileOutputFormat.setOutputPath(job, new Path(args[1]));
		job.waitForCompletion(true);
				

		FileSystem fs = FileSystem.get(config);
		FSDataInputStream in = fs.open(new Path("hdfs://localhost:9000" + args[1] + "/part-r-00000"));
		BufferedReader d = new BufferedReader(new InputStreamReader(in));
		
		int maxCount = 0;
		String ipAddress = "";
		String line = null;		
		
		while ((line = d.readLine()) != null) {
			String[] words = line.split("\t");
			int currentCount = Integer.parseInt(words[1]);
			if (currentCount > maxCount) {
				maxCount = currentCount;
				ipAddress = words[0];
			}
		}
		
		System.out.println();
		System.out.println("Maximum logged-in IP Address is: " + ipAddress);
		System.out.println("For " + maxCount + " times");
	}
}
