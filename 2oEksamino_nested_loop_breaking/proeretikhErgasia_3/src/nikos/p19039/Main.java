package nikos.p19039;

public class Main {
	
	public static void main(String[] args) {
        
        // se auth thn ergasia 8a kanw
		// emfoleumena loops pou spane me
			// 1) return
			// 2) labeled break
			// 3) labeled continue
		//gia na mporeite na to elenksete kalytera evala kathe ksexwristo block kwdika se sxolia
		
		
//-----------------------------------------------------------------------------------
	// 1) breaking a loop with return
		
		System.out.println("beginning of the loop");
		countingMembers();
		System.out.println("ending of the loop");
	
//-----------------------------------------------------------------------------------
	// 2) breaking a loop with labeled break
		
		/*System.out.println("beginning of the for loop");
		
		lbl1:
	        for (int y=0;y<100;y++){
	            for (int z=0;z<20;z++){
	                System.out.println(z);
	                if (z==11)
	                    break lbl1;  // Labeled break
	                System.out.println("Something");
	            }
	        }
	
		System.out.println("ending of the for loop");*/
		
		
//-----------------------------------------------------------------------------------
	// 3) breaking a loop with labeled continue
		
		/*System.out.println("beginning of the for loop");
		
		start: for (int i = 0; i < 5; i++) {
		         System.out.println(); // gia na allaksw seira
		         for (int j = 0; j < 12345; j++) {
		            System.out.print("#");
		            if (j >= i)
		               continue start;
		         }
		         System.out.println("This will never be printed");
		         }
		
		System.out.println(); // gia na allaksw seira
		System.out.println("ending of the for loop");*/
    }
	
	static void countingMembers() {
		int members = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for(int k = 0; k < 10; k++) {
					members++;
					if (members == 111) {
						System.out.println("Found the 111th member!!!!!");
						return;
					}
				}
			}
		}
	}
}
