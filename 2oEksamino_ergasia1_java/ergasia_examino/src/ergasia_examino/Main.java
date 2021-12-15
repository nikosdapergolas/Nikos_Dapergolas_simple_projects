package ergasia_examino;

import java.util.Scanner;  // Import the Scanner class
import java.io.*; 		   // for file managing
import java.util.ArrayList;

public class Main  {
	
//	int numberOfAnimals = 6;

	public static void main(String[] args) {
	
//----------------------------------------------------------------------------------
	//in this block of code i just paint the menu to the screen
		
		System.out.println("Program zoo");
		System.out.println("Here is the menu of choice");
		System.out.println("-----------------------------------------------");
		System.out.println("1.Show all the available animals in the zoo");
		System.out.println("2.Add an animal");
		System.out.println("3.Search for an animal based on its name");
		System.out.println("4.Search for an animal based on its code");
		System.out.println("5.Edit an animal based on its code");
		System.out.println("6.Delete an animal based on its code");
		System.out.println("7.Exit the program");
		System.out.println("-------------------------------------------------");

//-----------------------------------------------------------------------------------
	//this is the most important block of code
		//1) this while loop takes the choice of the user until the choice is number 7
		//2) when number 7 is inserted, then the program shuts down
		
		
		boolean exitMenu = true; //the ending condition of the while loop
		
		while (exitMenu) {
			
			System.out.println("Please insert one out of the seven numbers");
			Scanner myObj = new Scanner(System.in);
			String choice = myObj.nextLine();  // Enter your choice and press Enter
					
			
			exitMenu = choiceForMenu(choice);
			
		}
		
		System.out.println("End of the program Zoo");
		
		
}
//------------------------------------------------------------------------------------
	
	public static boolean choiceForMenu(String choice) {
//---------------------------------------------------------------------------------
	//in this block of code i'm passing the values in the allready existing objects i've made 
		
		Animal a1 =new Animal(); // first animal
		a1.setName("Lion");
		a1.setCode("001");
		a1.setKilograms("250");
		a1.setMaxAge("15");
		a1.setSpecies("Mammal");
		
		Animal a2 =new Animal();  //second animal
		a2.setName("Prrot");
		a2.setCode("002");
		a2.setKilograms("10");
		a2.setMaxAge("90");
		a2.setSpecies("Bird");
		
		Animal a3 =new Animal();  //third animal
		a3.setName("Zebra");
		a3.setCode("003");
		a3.setKilograms("200");
		a3.setMaxAge("30");
		a3.setSpecies("Mammal");
		
		Animal a4 =new Animal();  //fourth animal
		a4.setName("Seal");
		a4.setCode("004");
		a4.setKilograms("202");
		a4.setMaxAge("18");
		a4.setSpecies("Mammal");
		
		Animal a5 =new Animal();  //fifth animal
		a5.setName("Snake");
		a5.setCode("005");
		a5.setKilograms("97");
		a5.setMaxAge("9");
		a5.setSpecies("Reptile");
		
		Animal a6 =new Animal();  //sixth animal
		a6.setName("Eagle");
		a6.setCode("006");
		a6.setKilograms("7");
		a6.setMaxAge("20");
		a6.setSpecies("Bird");

//-----------------------------------------------------------------------------------
	//in this block of code: 
	//1) i make a separate txt file for each existing animal
	//2) i fulfill this txt file with the charachteristics of each animal separately
		
		String anAnimal = "Lion"; // tha to xrisimopoihsw argotera gia na ftiaksei o xristis kapoio diko tou object
		
		try {
			File file1 = new File(anAnimal + ".txt"); //i make a txt file for the first object
			if(!file1.exists()) {
				
				file1.createNewFile();
				
			} 
			
			PrintWriter pw1 = new PrintWriter(file1);
			pw1.println("Code: " + a1.getCode());
			pw1.println("Name: " + a1.getName());
			pw1.println("Species: " + a1.getSpecies());
			pw1.println("Weight: " + a1.getKilograms());
			pw1.println("Max age: " + a1.getMaxAge());
			pw1.println("--------------------------------------");
			pw1.close();
			
			File file2 = new File("Parrot.txt"); //i make a txt file for the second object
			if(!file2.exists()) {
				
				file2.createNewFile();
				
			} 
			
			PrintWriter pw2 = new PrintWriter(file2);
			pw2.println("Code: " + a2.getCode());
			pw2.println("Name: " + a2.getName());
			pw2.println("Species: " + a2.getSpecies());
			pw2.println("Weight: " + a2.getKilograms());
			pw2.println("Max age: " + a2.getMaxAge());
			pw2.println("--------------------------------------");
			pw2.close();
			
			File file3 = new File("Zebra.txt"); //i make a txt file for the third object
			if(!file3.exists()) {
				
				file3.createNewFile();
				
			} 
			
			PrintWriter pw3 = new PrintWriter(file3);
			pw3.println("Code: " + a3.getCode());
			pw3.println("Name: " + a3.getName());
			pw3.println("Species: " + a3.getSpecies());
			pw3.println("Weight: " + a3.getKilograms());
			pw3.println("Max age: " + a3.getMaxAge());
			pw3.println("--------------------------------------");
			pw3.close();
			
			File file4 = new File("Seal.txt"); //i make a txt file for the fourth object
			if(!file4.exists()) {
				
				file4.createNewFile();
				
			} 
			
			PrintWriter pw4 = new PrintWriter(file4);
			pw4.println("Code: " + a4.getCode());
			pw4.println("Name: " + a4.getName());
			pw4.println("Species: " + a4.getSpecies());
			pw4.println("Weight: " + a4.getKilograms());
			pw4.println("Max age: " + a4.getMaxAge());
			pw4.println("--------------------------------------");
			pw4.close();
			
			File file5 = new File("Snake.txt"); //i make a txt file for the firth object
			if(!file5.exists()) {
				
				file5.createNewFile();
				
			} 
			
			PrintWriter pw5 = new PrintWriter(file5);
			pw5.println("Code: " + a5.getCode());
			pw5.println("Name: " + a5.getName());
			pw5.println("Species: " + a5.getSpecies());
			pw5.println("Weight: " + a5.getKilograms());
			pw5.println("Max age: " + a5.getMaxAge());
			pw5.println("--------------------------------------");
			pw5.close();
			
			File file6 = new File("Eagle.txt"); //i make a txt file for the sixth object
			if(!file6.exists()) {
				
				file2.createNewFile();
				
			} 
			
			PrintWriter pw6 = new PrintWriter(file6);
			pw6.println("Code: " + a6.getCode());
			pw6.println("Name: " + a6.getName());
			pw6.println("Species: " + a6.getSpecies());
			pw6.println("Weight: " + a6.getKilograms());
			pw6.println("Max age: " + a6.getMaxAge());
			pw6.println("--------------------------------------");
			pw6.close();
			
		
			
		}
		catch (IOException e) {
					e.printStackTrace();
		}
	
//-------------------------------------------------------------------------------------			
	//in this block of code i make a list with the already existing animal names
	//and i also make a list with their codes respectively
		
		int numberOfAnimals = 6; // how many animals exist at the zoo at the point
		

		  ArrayList<String> listOfNames=new ArrayList<String>();//Creating arraylist    
	      listOfNames.add(a1.getName());//Adding object in arraylist    
	      listOfNames.add(a2.getName());    
	      listOfNames.add(a3.getName());    
	      listOfNames.add(a4.getName());    
	      listOfNames.add(a5.getName()); 
	      listOfNames.add(a6.getName()); 
	      //Invoking arraylist object   

	      
	      ArrayList<String> listOfCodes=new ArrayList<String>();//Creating arraylist    
	      listOfCodes.add(a1.getCode());//Adding object in arraylist    
	      listOfCodes.add(a2.getCode());    
	      listOfCodes.add(a3.getCode());    
	      listOfCodes.add(a4.getCode());    
	      listOfCodes.add(a5.getCode()); 
	      listOfCodes.add(a6.getCode()); 
	      //Invoking arraylist object   
	
//------------------------------------------------------------------------------------		
	//this choice origins in line 40
				
		switch (choice) {

//------------------------------------------------------------------------------------
	//this block of code contains the first choice from the menu
	//by the time the code in this block gets chosen, the proram scans all the files with the animals and prints them in the console
	
		  case "1":
			BufferedReader br1 = null;
			try {
				br1 = new BufferedReader(new FileReader(anAnimal + ".txt"));
				String line1;
				
				try {
					while((line1 = br1.readLine()) != null) {
						System.out.println(line1);
					}
				} catch (IOException e) {
					e.printStackTrace();
				}
				
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}finally {
				try {
					br1.close();
				} catch (IOException e) {
					e.printStackTrace();
				} 
			}
			
			BufferedReader br2 = null;
			try {
				br2 = new BufferedReader(new FileReader("Parrot.txt"));
				String line2;
				
				try {
					while((line2 = br2.readLine()) != null) {
						System.out.println(line2);
					}
				} catch (IOException e) {
					e.printStackTrace();
				}
				
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}finally {
				try {
					br2.close();
				} catch (IOException e) {
					e.printStackTrace();
				} 
			}
			
			BufferedReader br3 = null;
			try {
				br3 = new BufferedReader(new FileReader("Zebra.txt"));
				String line3;
				
				try {
					while((line3 = br3.readLine()) != null) {
						System.out.println(line3);
					}
				} catch (IOException e) {
					e.printStackTrace();
				}
				
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}finally {
				try {
					br3.close();
				} catch (IOException e) {
					e.printStackTrace();
				} 
			}

			BufferedReader br4 = null;
			try {
				br4 = new BufferedReader(new FileReader("Seal.txt"));
				String line4;
				
				try {
					while((line4 = br4.readLine()) != null) {
						System.out.println(line4);
					}
				} catch (IOException e) {
					e.printStackTrace();
				}
				
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}finally {
				try {
					br4.close();
				} catch (IOException e) {
					e.printStackTrace();
				} 
			}
			
			BufferedReader br5 = null;
						try {
							br5 = new BufferedReader(new FileReader("Snake.txt"));
							String line5;
							
							try {
								while((line5 = br5.readLine()) != null) {
									System.out.println(line5);
								}
							} catch (IOException e) {
								e.printStackTrace();
							}
							
						} catch (FileNotFoundException e) {
							e.printStackTrace();
						}finally {
							try {
								br5.close();
							} catch (IOException e) {
								e.printStackTrace();
							} 
						}
			
			BufferedReader br6 = null;
						try {
							br6 = new BufferedReader(new FileReader("Eagle.txt"));
							String line6;
							
							try {
								while((line6 = br6.readLine()) != null) {
									System.out.println(line6);
								}
							} catch (IOException e) {
								e.printStackTrace();
							}
							
						} catch (FileNotFoundException e) {
							e.printStackTrace();
						}finally {
							try {
								br6.close();
							} catch (IOException e) {
								e.printStackTrace();
							} 
						}
			
			return true;
//-----------------------------------------------------------------------------------
	//this block of code contains the second choice of the menu
	//by the time the user chooses it, he mast fulfill some blanks that are useful for the new animal
	//after he types them, a new txt file gets generated , which is exactly the same as the rest txt files
		
		  case "2":
			
			Animal a = new Animal();
			System.out.println("Please insert the name of the animal tha you want to add");
			Scanner objToInsert1 = new Scanner(System.in);
			String animalToBeInserted = objToInsert1.nextLine();
			a.setName(animalToBeInserted);
			System.out.println("Please insert the code of the animal tha you want to add");
			Scanner objToInsert2 = new Scanner(System.in);
			String codeToBeInserted = objToInsert2.nextLine();
			a.setCode(codeToBeInserted);
			System.out.println("Please insert the species of the animal tha you want to add");
			Scanner objToInsert3 = new Scanner(System.in);
			String speciesToBeInserted = objToInsert3.nextLine();
			a.setSpecies(speciesToBeInserted);
			System.out.println("Please insert the weight of the animal tha you want to add");
			Scanner objToInsert4 = new Scanner(System.in);
			String weightToBeInserted = objToInsert4.nextLine();
			a.setKilograms(weightToBeInserted);
			System.out.println("Please insert the max age of the animal tha you want to add");
			Scanner objToInsert5 = new Scanner(System.in);
			String maxAgeToBeInserted = objToInsert5.nextLine();
			a.setMaxAge(maxAgeToBeInserted);
			
			try {
				
				File file1 = new File(animalToBeInserted + ".txt"); 
				if(!file1.exists()) {
					
					file1.createNewFile();
					
				} 
				
				PrintWriter pw1 = new PrintWriter(file1);
				pw1.println("Code: " + a.getCode());
				pw1.println("Name: " + a.getName());
				pw1.println("Species: " + a.getSpecies());
				pw1.println("Weight: " + a.getKilograms());
				pw1.println("Max age: " + a.getMaxAge());
				pw1.println("--------------------------------------");
				pw1.close();
			}
			finally
			{

				return true;
			}

//----------------------------------------------------------------------------------
	//this block of code contains the third choice
	//the user types a name of an animal and it imidiately shows al of its charachteristics in the console
			
			
		  case "3":
			
			System.out.println("please insert the name of the animal that you want to edit: ");
			System.out.println(listOfNames);
			Scanner objToSearch = new Scanner(System.in);
			String animalToBeSearched = objToSearch.nextLine();
			boolean animalFound = true; //variable which i am going to use after the for loop to tell the user if the animal he searched exists
			for (int i = 0; i < numberOfAnimals; i++) {
				  if (listOfNames.contains(animalToBeSearched)) {
					  System.out.println("found it");
					  animalFound = false;
					  BufferedReader brNew = null;
						try {
							brNew = new BufferedReader(new FileReader(animalToBeSearched + ".txt"));
							String line;
							
							try {
								while((line = brNew.readLine()) != null) {
									System.out.println(line);
								}
							} catch (IOException e) {
								e.printStackTrace();
							}
							
						} catch (FileNotFoundException e) {
							e.printStackTrace();
						}finally {
							try {
								brNew.close();
							} catch (IOException e) {
								e.printStackTrace();
							}
							
					  break;
				  }
				}}
			if (animalFound) {
				  System.out.println("I am sorry. There is no such animal in the zoo");
			  }
			return true;

//------------------------------------------------------------------------------------
	//this lock of code contains the fourth choice from the menu
	//the user types the code of the animal tha he wants to search an then the program shows the details in the screen
	
		  
		  
		  case "4":
			  System.out.println("please insert the code of the animal that you want to search: ");
				System.out.println(listOfCodes);
				Scanner objToSearch2 = new Scanner(System.in);
				String codeToBeSearched = objToSearch2.nextLine();
				boolean codeFound = true; //the variable i am going to use after the for loop to inform the user if the animal he searched exists or not
				for (int i = 0; i < numberOfAnimals; i++) {
					  if (listOfCodes.contains(codeToBeSearched)) {
 
						  System.out.println("found it"); //sto telos tha to afairesw
						  codeFound = false;
						  BufferedReader brNew2 = null;
							try {
								brNew2 = new BufferedReader(new FileReader(listOfNames.get(listOfCodes.indexOf(codeToBeSearched)) + ".txt"));
								String line;
								
								try {
									while((line = brNew2.readLine()) != null) {
										System.out.println(line);
									}
								} catch (IOException e) {
									e.printStackTrace();
								}
								
							} catch (FileNotFoundException e) {
								e.printStackTrace();
							}finally {
								try {
									brNew2.close();
								} catch (IOException e) {
									e.printStackTrace();
								}
								
						  break;
					  }
					}}
				if (codeFound) {
					  System.out.println("I am sorry. There is no such animal in the zoo");
				  }
			return true;
			
//------------------------------------------------------------------------------------
	//this block of code contains the fifth choice from the menu
	//the user types a code of an animal that he wants to edit
	//after the editing, the file of the animal will change will from now on contain all the new elements
			
			
		  case "5":
			  System.out.println("please insert the code of the animal that you want to edit: ");
				System.out.println(listOfCodes);
				Scanner objToSearch3 = new Scanner(System.in);
				String codeToBeSearched2 = objToSearch3.nextLine();
				boolean codeFound2 = true; //the variable i am going to use after the for loop to inform the user if the animal he searched exists or not
				for (int i = 0; i < numberOfAnimals; i++) {
					  if (listOfCodes.contains(codeToBeSearched2)) {

						  System.out.println("found it"); //sto telos tha to afairesw
						  codeFound2 = false;
						  
						  
						  
						  BufferedReader brNew2 = null;
							try {
								brNew2 = new BufferedReader(new FileReader(listOfNames.get(listOfCodes.indexOf(codeToBeSearched2)) + ".txt"));
								String line;
								
								try {
									System.out.println("you chose to edit this animal: " + listOfNames.get(listOfCodes.indexOf(codeToBeSearched2)));
									System.out.println("------------------------------------");
									while((line = brNew2.readLine()) != null) {
										System.out.println(line);
									}
									
									System.out.println("Please insert the changed name of the animal tha you have chosen");
									Scanner objToInsert11 = new Scanner(System.in);
									String animalToBeChanged = objToInsert11.nextLine();

									System.out.println("Please insert the changed code of the animal tha you have chosen");
									Scanner objToInsert22 = new Scanner(System.in);
									String codeToBeChanged = objToInsert22.nextLine();

									System.out.println("Please insert the changed species of the animal tha you have chosen");
									Scanner objToInsert33 = new Scanner(System.in);
									String speciesToBeChanged = objToInsert33.nextLine();

									System.out.println("Please insert the changed weight of the animal tha you have chosen");
									Scanner objToInsert44 = new Scanner(System.in);
									String weightToBeChanged = objToInsert44.nextLine();

									System.out.println("Please insert the changed max age of the animal tha you have chosen");
									Scanner objToInsert55 = new Scanner(System.in);
									String maxAgeToBeChanged = objToInsert55.nextLine();

									
									File file1 = new File(animalToBeChanged + ".txt"); 
									if(file1.exists()) {
										
										file1.delete();
										file1.createNewFile();
										File file2 = new File(animalToBeChanged + ".txt");
										PrintWriter pw = new PrintWriter(file2);
										
										pw.println("Code: " + codeToBeChanged);
										pw.println("Name: " + animalToBeChanged);
										pw.println("Species: " + speciesToBeChanged);
										pw.println("Weight: " + weightToBeChanged);
										pw.println("Max age: " + maxAgeToBeChanged);
										pw.println("--------------------------------------");
										pw.close();
										
										
									}
								} catch (IOException e) {
									e.printStackTrace();
								}
								
							} catch (FileNotFoundException e) {
								e.printStackTrace();
							}finally {
								try {
									brNew2.close();
								} catch (IOException e) {
									e.printStackTrace();
								}
								
						  break;
					  }
					}}
				if (codeFound2) {
					  System.out.println("I am sorry. There is no such animal in the zoo");
				  }
		    return true;
		    
//-----------------------------------------------------------------------------------------
	//this block of code contains the sixth choice from the menu
	//the user chooses a code from the animal that he wants it to be deleted. Afterwards the txt file from the animal gets deleted
	
		    
		    
		  case "6":
			  System.out.println("Please insert the code of the animal that you want to delete: ");
				System.out.println(listOfCodes);
				Scanner objToSearch4 = new Scanner(System.in);
				String codeToBeSearched3 = objToSearch4.nextLine();
				boolean codeFound3 = true; //the variable i am going to use after the for loop to inform the user if the animal he searched exists or not
				for (int i = 0; i < numberOfAnimals; i++) {
					  if (listOfCodes.contains(codeToBeSearched3)) {
 
						  System.out.println("Ok. Animal is deleted!"); //sto telos tha to afairesw
						  codeFound3 = false;
						  BufferedReader brNew2 = null;
						  File file = new File(listOfNames.get(listOfCodes.indexOf(codeToBeSearched3)) + ".txt");
						  file.delete();
						  break;

						  
					  }}
			return true;
			
//-----------------------------------------------------------------------------------------
	//this block of code contains the seventh and last choice from the menu 
	//its the ending term of the program
	//by the time it gets chosen the program shuts down and it saves the animals
			
			
		  case "7":
		
			 System.out.println("7.Exit the application");
			 return false;
			
//---------------------------------------------------------------------------------------------
	//this block of code contains the message that shows to the user
	//its what happens if the user happens to type something else than 1,2,3,4,5,6,7
			 
			
		  default:
			System.out.println("Sorry, you typed incorrect code. Try again");//to exeption
			return true;
		}

	}

//---------------------------------------------------------------------------------------------	
	
}
