
#include <iostream>
#include <string>
using namespace std;

// Class for managing server information
class Server
{
private:
    int serverID;
    string serverName;
    bool status;

public:

    // Constructor
    Server(int id, string name, bool s)
    {
        serverID = id;
        serverName = name;
        status = s;
    }

    // Change server status
    void changeStatus(bool s)
    {
        status = s;
    }

    // Check if server is online
    bool isOnline()
    {
        return status;
    }

    // Display server details
    void displayStatus()
    {
        cout << "Server ID: " << serverID << endl;
        cout << "Server Name: " << serverName << endl;

        if(status)
            cout << "Status: ONLINE" << endl;
        else
            cout << "Status: OFFLINE" << endl;
    }
};

int main()
{
    Server s1(1, "Main Server", true);
    Server s2(2, "Backup Server", true);
    Server s3(3, "Secondary Server", false);

    int choice;

    do
    {
        cout << "\n===== NETWORK MONITORING SYSTEM =====" << endl;
        cout << "1. View Server Status" << endl;
        cout << "2. Turn Server OFFLINE" << endl;
        cout << "3. Turn Server ONLINE" << endl;
        cout << "4. Exit" << endl;
        cout << "5. Network Availability Report" << endl;
        cout << "6. Automatic Failover Check" << endl;
        cout << "7. Network Dashboard" << endl;
        cout << "8. Deployment Simulator" << endl;
        cout << "9. System Health Check" << endl;
        cout << "10. Server Recovery Report" << endl;

        cout << "\nEnter Choice: ";
        cin >> choice;

        if(choice == 1)
        {
            cout << "\n--- SERVER STATUS ---" << endl;

            s1.displayStatus();
            cout << endl;

            s2.displayStatus();
            cout << endl;

            s3.displayStatus();
        }

        else if(choice == 2)
        {
            int id;

            cout << "Enter Server ID (1-3): ";
            cin >> id;

            if(id == 1)
                s1.changeStatus(false);
            else if(id == 2)
                s2.changeStatus(false);
            else if(id == 3)
                s3.changeStatus(false);
            else
                cout << "Invalid Server ID!" << endl;
        }

        else if(choice == 3)
        {
            int id;

            cout << "Enter Server ID (1-3): ";
            cin >> id;

            if(id == 1)
                s1.changeStatus(true);
            else if(id == 2)
                s2.changeStatus(true);
            else if(id == 3)
                s3.changeStatus(true);
            else
                cout << "Invalid Server ID!" << endl;
        }

        else if(choice == 5)
        {
            int active = 0;
            int failed = 0;

            if(s1.isOnline())
                active++;
            else
                failed++;

            if(s2.isOnline())
                active++;
            else
                failed++;

            if(s3.isOnline())
                active++;
            else
                failed++;

            float availability = (active * 100.0) / 3;

            cout << "\n--- NETWORK SUMMARY ---" << endl;
            cout << "Total Servers: 3" << endl;
            cout << "Active Servers: " << active << endl;
            cout << "Failed Servers: " << failed << endl;
            cout << "Network Availability: " << availability << "%" << endl;
        }

        else if(choice == 6)
        {
            cout << "\n--- AUTOMATIC FAILOVER CHECK ---" << endl;

            if(s1.isOnline())
            {
                cout << "Main Server is ACTIVE." << endl;
            }
            else if(s2.isOnline())
            {
                cout << "Main Server is DOWN!" << endl;
                cout << "Backup Server Activated!" << endl;
            }
            else if(s3.isOnline())
            {
                cout << "Main and Backup Servers are DOWN!" << endl;
                cout << "Secondary Server Activated!" << endl;
            }
            else
            {
                cout << "All Servers are OFFLINE!" << endl;
            }
        }

        else if(choice == 7)
        {
            int active = 0;
            int failed = 0;

            cout << "\n===== NETWORK DASHBOARD =====" << endl;
            cout << "\nSERVER DETAILS:" << endl;

            s1.displayStatus();
            cout << endl;

            s2.displayStatus();
            cout << endl;

            s3.displayStatus();
            cout << endl;

            if(s1.isOnline()) active++;
            else failed++;

            if(s2.isOnline()) active++;
            else failed++;

            if(s3.isOnline()) active++;
            else failed++;

            float availability = (active * 100.0) / 3;

            cout << "Total Servers: 3" << endl;
            cout << "Active Servers: " << active << endl;
            cout << "Failed Servers: " << failed << endl;
            cout << "Network Availability: " << availability << "%" << endl;
        }

        else if(choice == 8)
        {
            int deployChoice;

            cout << "\n===== DEPLOYMENT SIMULATOR =====" << endl;
            cout << "1. Deploy Application" << endl;
            cout << "2. Rebuild Application" << endl;
            cout << "Enter Choice: ";
            cin >> deployChoice;

            if(deployChoice == 1)
            {
                cout << "\nApplication Deployed Successfully!" << endl;
            }
            else if(deployChoice == 2)
            {
                cout << "\nRebuilding Application..." << endl;
                cout << "Application Rebuilt Successfully!" << endl;
            }
            else
            {
                cout << "Invalid Deployment Choice!" << endl;
            }
        }

        else if(choice == 9)
        {
            cout << "\n===== SYSTEM HEALTH CHECK =====" << endl;

            if(s1.isOnline() && s2.isOnline() && s3.isOnline())
            {
                cout << "System Health: EXCELLENT" << endl;
            }
            else if(s1.isOnline() || s2.isOnline() || s3.isOnline())
            {
                cout << "System Health: WARNING" << endl;
            }
            else
            {
                cout << "System Health: CRITICAL" << endl;
            }
        }

        else if(choice == 10)
        {
            cout << "\n===== SERVER RECOVERY REPORT =====" << endl;

            if(!s1.isOnline())
                cout << "Main Server needs recovery!" << endl;

            if(!s2.isOnline())
                cout << "Backup Server needs recovery!" << endl;

            if(!s3.isOnline())
                cout << "Secondary Server needs recovery!" << endl;

            if(s1.isOnline() && s2.isOnline() && s3.isOnline())
                cout << "All Servers are Healthy!" << endl;
        }

        else if(choice == 4)
        {
            cout << "Thank you for using Network Monitoring System!" << endl;
        }

        else
        {
            cout << "Invalid Choice!" << endl;
        }

    } while(choice != 4);

    return 0;
}


