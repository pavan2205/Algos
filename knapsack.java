import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
 
public class KnapsackProblem {
 
	private int n;		//number of objects
	private int[] p;	//array of profits
	private int[] s; 	//array of sizes
	private int B; 		//capacity of knapsack
 
	private boolean[] solution;  	//optimal solution given by boolean array
	private int Z;		   			//optimal objective value
 
 
	//accessor methods
	public int getN(){
		return this.n;
	}
	public int[] getProfits(){
		return this.p;
	}
	public int[] getSizes(){
		return this.s;
	}
	public int getCapacity(){
		return this.B;
	}
	public int getZ(){
		return this.Z;
	}
	public boolean[] getSolution(){
		return this.solution;
	}
 
	//mutator methods
	public void setZ(int Z){
		this.Z = Z;
	}
	public void setSolution(boolean[] solution){
		this.solution = solution;
	}
 
	//constructor override; assumes p and s have length n
	public KnapsackProblem(int n, int p[], int s[], int B){
		this.n = n;
		this.p = p;
		this.s = s;
		this.B = B;
	}
 
	//solve problem using Dynamic Programming for Knapsack
	public void solve(){
		DynamicKnapsack.solve(this);
	}
 
	//write an lp file of the associated IP for CPLEX to solve
	public void writeLP(){
		PrintWriter out = null;
		try{
			File lp = new File("knapsack" + n + ".lp");
 
			out = new PrintWriter(new BufferedWriter(new FileWriter(lp, false)));		
		} catch(Exception e){
			e.getMessage();
			System.exit(0);
		}
		out.println("Maximize");	
 
		//print objective
		out.print(" obj: ");
		out.print(p[0] + " x0");
		for(int i=1; i<n; i++)
			out.print(" + " + p[i] + " x" + i );
		out.println();
 
		//print constraint
		out.println("Subject To");
		out.print(" c1: " + s[0] + " x0");
		for(int i=1; i<n; i++)
			out.print(" + " + s[i] + " x" + i);
		out.println(" <= " + B);
 
		//domain restriction
		out.println("Binaries");
		for(int i=0; i<n; i++)
			out.println(" x" + i);
 
		out.println("End");
		out.close();	
		System.out.println("LP file written. \n");
	}//end method writeLP()
 
}//end class KnapsackProblem
