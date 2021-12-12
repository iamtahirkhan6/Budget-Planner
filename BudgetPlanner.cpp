class BudgetPlanner {       
  public:             
    float TotalBalance=0;
    
    //pass the vector containing the balance of all the months 
    void UpdateTotalBalance(vector<string> &v){
        for (int i=0; i < 12; i++)
         {
             TotalBalance = TotalBalance + v[i] ;
         }
        return TotalBalance;
    };
    
    void ReadDocument(vector<string> &v){
  	  ifstream file;
  	  file.open("budget.txt");
  	  string line;
  	  while(getline(file, line)){
  		  v.push_back(line);
  	  }
  	 file.close();
    }

    void WriteDocument(vector<string> &v){
      ofstream file;
	    file.open("budget.txt");
	    for(int i=0; i < v.size(); ++i){
		    file << v[i] << endl;
	    }
	    file.close(); 
    }
};
