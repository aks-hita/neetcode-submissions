class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size()==0) return 0;
        vector<vector<double>> car(position.size(),vector<double>(2));
        stack<double> fleet;
        for(int i=0;i<position.size();i++){
            car[i][0]=position[i];
            car[i][1]=(double)(target-position[i])/speed[i];
        }
        sort(car.begin(),car.end(),greater<vector<double>>());
        fleet.push(car[0][1]);
        for(int i=1;i<position.size();i++){
            if(car[i][1]>fleet.top()) fleet.push(car[i][1]);
        }
        return fleet.size();
    }
};
