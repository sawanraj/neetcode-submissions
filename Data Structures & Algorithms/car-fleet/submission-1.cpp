class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        if(n==0)
        return 0;

        vector<pair<int,double>>cars(n);// pair of position and time consumed to reach target
        for(int i=0;i<n;++i){
            double time=static_cast<double>(target-position[i])/speed[i]; //find time 
            cars[i]={position[i],time}; //store cars in pair with time
        }
        //Sorted the pair by using car position
        sort(cars.begin(),cars.end(),[](const auto& a,const auto& b){
            return a.first>b.first;
        });
        int fleetcount=0;//fleet is group of car taking almost same time to reach target
        double maxtime=0.0;
        for(const auto& car:cars){
            //So, if any car taking more than the maxtime it will form new group/fleet
            if(car.second >maxtime){
                fleetcount++; 
                maxtime=car.second;
            }
        }
    return fleetcount;
    }
};
