#include <iostream>

using namespace std;

bool TrainingSet[10][15] = {
    {
        1,1,1,1,0,1,1,0,1,1,0,1,1,1,1
    },
    {
        0,0,1,0,0,1,0,0,1,0,0,1,0,0,1
    },
    {
        1,1,1,0,0,1,1,1,1,1,0,0,1,1,1
    },
    {
        1,1,1,0,0,1,1,1,1,0,0,1,1,1,1
    },
    {
        1,0,1,1,0,1,1,1,1,0,0,1,0,0,1
    },
    {
        1,1,1,1,0,0,1,1,1,0,0,1,1,1,1
    },
    {
        1,1,1,1,0,0,1,1,1,1,0,1,1,1,1
    },
    {
        1,1,1,0,0,1,0,0,1,0,0,1,0,0,1
    },
    {
        1,1,1,1,0,1,1,1,1,1,0,1,1,1,1
    },
    {
        1,1,1,1,0,1,1,1,1,0,0,1,1,1,1
    }
};

bool TestSet[7][15] = {
    {
        1,1,1,1,0,0,1,1,1,0,0,1,1,1,1
    },
    {
        1,1,1,1,0,0,1,1,1,0,0,0,1,1,1
    },
    {
        1,1,1,1,0,0,0,1,0,0,0,1,1,1,1
    },
    {
        1,1,1,1,0,0,0,1,1,0,0,1,1,1,1
    },
    {
        1,1,0,1,0,0,1,1,1,0,0,1,1,1,1
    },
    {
        1,1,0,1,0,0,1,1,1,0,0,1,0,1,1
    },
    {
        1,1,1,1,0,0,1,0,1,0,0,1,1,1,1
    }
};

//Neuron
int Weights[15];
int Threshold;

void NeuronInitialization()
{
    for (int i = 0; i < 15; i++)
        Weights[i] = i;
    Threshold = 84;
}

bool NeuroResult(bool Inputs[])
{
    //Adder (Net)
    int Net = 0;
    for (int i = 0; i < 15; i++)
        Net += Inputs[i] * Weights[i];
    //F_Activation f(net) (Exit)
    return Net >= Threshold;
}

void Training(int Number)
{
    bool Inputs[15];
    bool result;
    int count = 0;
    for (int j=0, exit_condition = 0;exit_condition<10;j++, count++)
    {
        if (j == 10)
            j = 0;
        for (int i = 0; i < 15; i++)
            Inputs[i] = TrainingSet[j][i];

        result = NeuroResult(Inputs);

        exit_condition++;

        if (result && j != Number)
        {
            exit_condition = 0;
            for (int i = 0; i < 15; i++)
                if (TrainingSet[j][i] == 1)
                    Weights[i]--;
        }

        if (!result && j == Number)
        {
            exit_condition = 0;
            for (int i = 0; i < 15; i++)
                if (TrainingSet[j][i] == 1)
                    Weights[i]++;
        }

    }
    //cout << "Count of traing steps: " << count << endl;
}

int main()
{
    NeuronInitialization();

    cout << "Perseptron test" << endl;
    cout << "Weights:";
    for (int i = 0; i < 15; i++)
        cout << Weights[i] << " ";
    cout << endl << endl;

    bool Inputs[15];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 15; j++)
            Inputs[j] = TrainingSet[i][j];
        cout<<i<<" - "<<NeuroResult(Inputs)<<endl;
    }

    Training(5);


    cout << "Weights:";
    for (int Weight : Weights)
        cout << Weight << " ";
    cout << endl << endl;

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 15; j++)
            Inputs[j] = TestSet[i][j];
        cout << i << " - " << NeuroResult(Inputs) << endl;
    }
}