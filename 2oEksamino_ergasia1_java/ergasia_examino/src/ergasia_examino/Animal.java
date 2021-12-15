package ergasia_examino;

import java.io.Serializable; 

public class Animal implements Serializable {
	private String code;
    private String species;
    private String Name;
    private String kilograms;
    private String maxAge;
    
	
    public String getCode() {
		return code;
	}
    
	public void setCode(String code) {
		this.code = code;
	}
	
	public String getSpecies() {
		return species;
	}
	
	public void setSpecies(String species) {
		this.species = species;
	}
	
	public String getName() {
		return Name;
	}
	
	public void setName(String name) {
		Name = name;
	}

	public String getKilograms() {
		return kilograms;
	}

	public void setKilograms(String kilograms) {
		this.kilograms = kilograms;
	}

	public String getMaxAge() {
		return maxAge;
	}

	public void setMaxAge(String maxAge) {
		this.maxAge = maxAge;
	}
	

}
