#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct packets
{
    long long arrival_time;
    long long process_time;
    long long index;
};

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

int main()
{
    long long buffer_size = 0;
    long long no_of_packets = 0;
    long long lc = 0;
    long long finish_time = 0;
   
    cin>>buffer_size>>no_of_packets;
    
    if(no_of_packets > 0)
    {
        vector<long long> result(no_of_packets);
        vector<packets> input(no_of_packets);
        queue<packets> buffer;

        for(lc = 0; lc < no_of_packets; lc++)
        {
            cin>>input[lc].arrival_time>>input[lc].process_time;
            input[lc].index = lc;
        }

        lc = 0;
        finish_time = input[0].arrival_time;

        while(lc < no_of_packets)
        {
            while(buffer.size() < buffer_size)
            {
                /*
                    * INPUT PHASE
                    * Firstly all the data packets are pushed into buffer 
                    * till the buffer gets full
                */
                buffer.push(input[lc]);
                lc++;
            }
            while(!buffer.empty())
            {
                /*
                    * PROCESSING PHASE
                    * The packets are now processed by the computer.
                    * While processing, if the packet from the buffer is taken and
                    * the if the buffer has one empty memory,
                    * then, all the packets that arrived while processing is dropped,
                    * and the packet that arrived after processing a packet from the buffer,
                    * is pushed into the buffer and the processing is continued.
                */
                while(buffer.size() < buffer_size && (lc < no_of_packets))
                {
                    if(finish_time <= input[lc].arrival_time)
                    {
                        buffer.push(input[lc]);
                        lc++;
                    }
                    else if(input[lc].arrival_time < finish_time)
                    {
                        result[lc] = -1;
                        lc++;
                    }
                }
                result[buffer.front().index] = finish_time;
                
                finish_time += buffer.front().process_time;
                buffer.pop();
                finish_time = max(finish_time, buffer.front().arrival_time);

            }

            /*
                * If many packets arrive at the same time and the buffer cannot accommodate it,
                * then they are all dropped.
            */
            while((input[lc].arrival_time < finish_time) && (lc < no_of_packets))
            {
                result[lc] = -1;
                lc++;
            }
            
            /*
                * Finish time is altered because,
                Consider the e.g., 
                Buffer size = 1
                No.of packets = 2
                1st packet:
                    arr_time = 0
                    proc_time = 1
                2cnd packets:
                    arr_time = 5
                    proc_time = 1
                
                * Here the computer  should wait for 4 milli seconds after processing
                * 1st packet, thus finish_time is altered.
            */
            finish_time = max(finish_time, input[lc].arrival_time);
        }
        
        for(lc = 0; lc < no_of_packets; lc++)
        {
            cout<<result[lc]<<endl;
        }
    }
}


/*
    TO UNDERSTAND


    Test cases
    1)
        1 5
        0 1
        1 1
        2 1
        3 1
        3 1
    2) 
        2 5
        0 417
        0 842
        0 919
        0 732
        418 414
    3)
        1 5
        0 417
        0 842
        0 919
        0 732
        417 414
    4)
        2 3
        0 1
        3 1
        10 1
    5)
        2 3
        0 2
        1 4
        5 3
    6)
        1 2
        0 1
        2 1
    7)
        1 2
        0 0
        0 1
    8)
        1 2
        0 0
        0 0
    9)
        3 6
        0 2
        1 2
        2 2
        3 2
        4 2
        5 2
*/