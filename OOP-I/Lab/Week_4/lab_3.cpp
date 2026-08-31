#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class cricket{
	private:	
		string player_code;
		string player_name;
		int matches;
		int runs;
		int not_out;
		float battingAvg;
		void calculate_average(){
			int dismissals = matches - not_out;
			if(dismissals > 0){
				battingAvg = (float) runs / dismissals;
			}else if(runs > 0 ){
				battingAvg = runs;
			}else{
				battingAvg = 0.0;
			}
		}
	
	public:
		cricket(){
			player_code = "";
			player_name = "";
			matches = 0;
			runs = 0;
			not_out = 0;
			battingAvg = 0.0;
		}
		cricket(string code, string name, int tot_matches, int tot_runs, int tot_not_out){
			player_code = code;
			player_name = name;
			matches = tot_matches;
			runs = tot_runs;
			not_out = tot_not_out;
			calculate_average();
		}
		void acceptDetails() {
        cout << "Enter Player Code: ";
        cin >> player_code;
        cout << "Enter Player Name: ";
        cin.ignore();
        getline(cin, player_name);
        cout << "Number of Matches Played: ";
        cin >> matches;
        cout << "Total Runs Scored: ";
        cin >> runs;
        cout << "Number of Times Not Out: ";
        cin >> not_out;
        calculate_average();
    }
	void displayAverage() const{
		cout<<fixed<<setprecision(2);
		cout<<"Player : "<<player_name <<" ("<<player_code << " ) | batting Average : "<<battingAvg<<endl;
	}
	static void displayAverage(cricket players[], int n){
		cout<<"\n --- Batting Average of All the Players ---"<<endl;
		float sumAverages = 0.0f;
		for(int i = 0; i < n; i++){
			players[i].displayAverage();
			sumAverages += players[i].battingAvg;
		}
		if(n > 0){
			cout<<"\nTeam Average Batting Rating : "<<(sumAverages / n)<<endl;
		}
	}
	
	int getTotalRuns() const{
		return runs;
	}
	void displayDetails() const{
		cout << left
             << setw(15) << player_code
             << setw(20) << player_name
             << setw(15) << matches
             << setw(15) << runs
             << setw(12) << not_out
             << setw(15) << fixed
             << setprecision(2) << battingAvg
             << endl;
    }
	static void displaySortedByRuns(cricket players[], int n) {
	    cricket temp[10];
	
	    // Copy players
	    for(int i = 0; i < n; i++) {
	        temp[i] = players[i];
	    }
	
	    // Sort by total runs - highest to lowest
	    for(int i = 0; i < n - 1; i++) {
	        for(int j = 0; j < n - i - 1; j++) {
	
	            if(temp[j].getTotalRuns() <
	               temp[j + 1].getTotalRuns()) {
	
	                cricket swapObj = temp[j];
	                temp[j] = temp[j + 1];
	                temp[j + 1] = swapObj;
	            }
	        }
	    }
	
	    cout << "\n--- Players sorted by Total Runs (Highest to Lowest) ---"
	         << endl;
	
	    // Column headings
	    cout << left
	         << setw(15) << "Player Code"
	         << setw(20) << "Player Name"
	         << setw(15) << "Matches"
	         << setw(15) << "Total Runs"
	         << setw(12) << "Not Out"
	         << setw(15) << "Average"
	         << endl;
	
	    cout << "--------------------------------------------------------------------------"
	         << endl;
	
	    // Display sorted players
	    for(int i = 0; i < n; i++) {
	        temp[i].displayDetails();
	    }
	}
	string getPlayerCode() const {
	    return player_code;
	}
};
int main(){
	cricket team[10];
	int ch, count = 0;
	do{
		cout << "\n=== Cricket Player Management Menu ===" << endl;
        cout << "1. Enter details of players" << endl;
        cout << "2. Display average runs of a single player" << endl;
        cout << "3. Average runs of all players" << endl;
        cout << "4. Display the list of players in sorted order as per total runs" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch(ch){
        	case 1:{
        		cout<<"Enter number of players to add (max " <<10 - count<< "): ";
        		int n;
        		cin>>n;
        		if(n + count > 10){
        			cout<<"Exceeds maximum limit of 10 players !"<<endl;
	        	}else{
	        		for(int i =0; i <n; i++){
	        			cout<<"\nEntering details for player : "<<count + 1<<" : "<<endl;
						team[count].acceptDetails();
						count++;						
					}
				}
				break;
			}
			case 2:{
				if (count == 0) {
                    cout << "No players found. Enter details first." << endl;
                    break;
                }
                cout << "Enter Player Code to search: ";
                string code;
                cin >> code;
                bool found = false;
                for (int i = 0; i < count; i++) {
                    if (team[i].getPlayerCode() == code) {
                        team[i].displayAverage();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Player with code " << code << " not found!" << endl;
                }
                break;
            }
            case 3: {
                if (count == 0) {
                    cout << "No players found." << endl;
                } else {
                    cricket::displayAverage(team, count);
                }
                break;
            }
            case 4: {
                if (count == 0) {
                    cout << "No players found." << endl;
                } else {
                    cricket::displaySortedByRuns(team, count);
                }
                break;
            }
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (ch != 5);

    return 0;
}
