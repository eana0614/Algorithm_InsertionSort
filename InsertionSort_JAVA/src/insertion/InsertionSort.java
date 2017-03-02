package insertion;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class InsertionSort {
	private static int arrayLength = 1000;

	public static void main (String[] args){
		
		String filePath = "random.txt";
		String fileName = "java insertion sort.txt";
		
		int[] readArray;
		
		try {
			readArray = readInputFile(filePath);
			int[] sortedArray = insertionSort(readArray);
			writeSortedFile(fileName, sortedArray);
			System.out.println("DONE");
			
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		
	}
	
	private static void writeSortedFile(String fn, int[] array) throws IOException{
		File ouputFile = new File(fn);
		FileOutputStream fos = new FileOutputStream(ouputFile);
		OutputStreamWriter osw = new OutputStreamWriter(fos);
		BufferedWriter bw = new BufferedWriter(osw);
		
		for(int i=0; i<array.length; i++){
			bw.write(String.valueOf(array[i]));
			bw.newLine();
		}
		
		bw.close();
		osw.close();
		fos.close();
	}

	private static int[] readInputFile(String filePath) throws IOException   {
		File inputFile = new File(filePath);
		FileInputStream fis = new FileInputStream(inputFile);
		InputStreamReader isr = new InputStreamReader(fis);
		BufferedReader br = new BufferedReader(isr);
		
		int[] tempArray = new int[arrayLength];
		
		String s;
		int i=0;
		
		while((s = br.readLine())!=null){
			tempArray[i]= Integer.parseInt(s);
			i++;
		}
		
		br.close();
		isr.close();
		fis.close();
		
		return tempArray;
	}

	private static int[] insertionSort(int[] array) {
		int length = array.length;
	
		for(int i=1; i<length; i++){
			int key = array[i];
			int j = i-1;
			while(j>=0 && array[j]>key){
				array[j+1] = array[j];
				j = j-1;
			}
			array[j+1] = key;
		}
		return array;
	}

}
