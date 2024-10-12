#include <bits/stdc++.h>

using namespace std;

//Design a Parking Lot -> https://codezym.com/question/1
class solution{
        vector<vector<vector<string>>> parking;
        map<string,pair<string,string>> spotIdDetails,vehicle,ticket;
        vector<string> spotForFourWheeler,spotForTwoWheeler;
    public:
        void init(vector<vector<vector<string>>> vc)
        {
            parking = vc;

            for(int i = 0;i < parking.size();i++)
            {
                for(int j = 0;j < parking[i].size();j++)
                {
                    for(int k = 0;k < parking[i][j].size();k++)
                    {
                        if(parking[i][j][k][2] == '1')
                        {
                            string spotId = to_string(i);
                            spotId += '-';
                            spotId += to_string(j);
                            spotId += '-';
                            spotId += to_string(k);
                            if(parking[i][j][k][0] == '4')
                                spotForFourWheeler.push_back(spotId);
                            else
                                spotForTwoWheeler.push_back(spotId);
                        }
                    }
                }
            }
            // for(auto &j:spotForFourWheeler)
            //     cout << j << endl;
            // cout << endl;
            // for(auto &j:spotForTwoWheeler)
            //     cout << j << endl;
        }

        void park(int vehicleType,string vehicleNumber,string ticketId)
        {
            if(vehicleType == 4)
            {
                if(!spotForFourWheeler.empty())
                {
                    spotIdDetails[spotForFourWheeler.back()] = {vehicleNumber,ticketId};
                    vehicle[vehicleNumber] = {spotForFourWheeler.back(),ticketId};
                    ticket[ticketId] = {spotForFourWheeler.back(),vehicleNumber};
                    cout << 201 << " " << spotForFourWheeler.back() << " " << vehicleNumber << " " << ticketId << endl;
                    spotForFourWheeler.pop_back();
                }
                else
                    cout << 404 << " " << "" << " " << vehicleNumber << " " << ticketId << endl;
            }
            else
            {
                if(!spotForTwoWheeler.empty())
                {
                    spotIdDetails[spotForTwoWheeler.back()] = {vehicleNumber,ticketId};
                    vehicle[vehicleNumber] = {spotForTwoWheeler.back(),ticketId};
                    ticket[ticketId] = {spotForTwoWheeler.back(),vehicleNumber};
                    cout << 201 << " " << spotForTwoWheeler.back() << " " << vehicleNumber << " " << ticketId << endl;
                    spotForTwoWheeler.pop_back();
                }
                else
                    cout << 404 << " " << "" << " " << vehicleNumber << " " << ticketId << endl;
            }
        }

        void removeVehicle(string spotId,string vehicleNumber,string ticketId)
        {
            if(spotId == "")
            {
                if(vehicleNumber != "")
                    spotId = vehicle[vehicleNumber].first;
                else
                    spotId = ticket[ticketId].first;
            }
            if(spotId != "")
            {
                if(spotIdDetails.count(spotId))
                {
                    int floor = spotId[0]-'0';
                    int row = spotId[2]-'0';
                    int column = spotId[4]-'0';
                    if(parking[floor][row][column][2] == '4')
                        spotForFourWheeler.push_back(spotId);
                    else
                        spotForTwoWheeler.push_back(spotId);
                    spotIdDetails.erase(spotId);
                    cout << 201 << " Successfully Removed" <<endl;
                }
                else
                    cout << 404 << endl;
            }
            else 
                cout << 404 << endl;
        }

        void searchVehicle(string spotId,string vehicleNumber,string ticketId)
        {
            if(spotId == "")
            {
                if(vehicleNumber != "")
                    spotId = vehicle[vehicleNumber].first;
                else
                    spotId = ticket[ticketId].first;
            }
            if(spotId != "")
                cout << 201 << " " << spotId << endl;
            else
                cout << 404 << " Not Found " << endl;
        }

        int getFreeSpotsCount(int floor,int vehicleType)
        {
            int freeSpots = 0;
            char ch = vehicleType+'0';
            for(int row = 0;row < parking[floor].size();row++)
            {
                for(int col = 0;col < parking[floor][row].size();col++)
                {
                    if(parking[floor][row][col][2] == '1' and parking[floor][row][col][0] == ch)
                    {
                        string spotId = to_string(floor);
                        spotId += '-';
                        spotId += to_string(row);
                        spotId += '-';
                        spotId += to_string(col);
                        if(!spotIdDetails.count(spotId))
                            freeSpots++;
                    }
                }
            }
            cout << "FreeSpots In Floor " << floor << " for " << (vehicleType==4?"Four Wheeler = ":"Two Wheeler = ") << freeSpots << endl;
        }
};



int main()
{
    solution obj;
    obj.init(
        {
            {
                {"4-1","4-1","2-1","2-0"},
                {"2-1","4-1","2-1","2-1"},
                {"4-0","2-1","4-0","2-1"},
                {"4-1","4-1","4-1","2-1"}
            }
        }
    );
    obj.park(4, "bh234", "tkt4534");
    obj.searchVehicle("","bh234","");
    obj.searchVehicle("","","tkt4534");
    obj.getFreeSpotsCount(0,4);
    // obj.removeVehicle("0-3-2","","");
    //obj.removeVehicle("","bh234","");
    obj.removeVehicle("","","tkt4534");
    obj.getFreeSpotsCount(0,4);
    return 0;
}