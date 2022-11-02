#include <iostream>
#include <map>

class Bacterium {
public:
    void setName( std::string name ) {
        name_ = name;
    }

    std::string getName() {
        return name_;
    }

    void setSize( double size ) {
        size_ = size;
    }

    double getSize() {
        return size_;
    }

protected:
    std::string name_ {};
    double size_ {};
};

class Insect : public Bacterium {
public:
    Insect() {
        name_ = "Butterfly";
        size_ = 5;
    }

    void setnumberOfLimbs( int numberOfLimbs ) {
        numberOfLimbs_ = numberOfLimbs;
    }

    int getnumberOfLimbs() {
        return numberOfLimbs_;
    }

    void setnumberOfEyes( int numberOfEyes ) {
        numberOfEyes_ = numberOfEyes;
    }

    int getnumberOfEyes() {
        return numberOfEyes_;
    }

protected:
    int numberOfLimbs_ { 6 };
    int numberOfEyes_ { 2 };
};

class Human : public Insect {
public:
    Human() {
        name_ = "Heorhii";
        size_ = 185.2;
        numberOfLimbs_ = 4;
        numberOfEyes_ = 2;
    }

    void setJob( std::string job ) {
        job_ = job;
    }

    std::string getJob() {
        return job_;
    }

    void setNationality( std::string nationality ) {
        nationality_ = nationality;
    }

    std::string getNationality() {
        return nationality_;
    }

    void setAge( int age ) {
        age_ = age;
    }

    int getAge() {
        return age_;
    }

private:
    std::string job_ { "Engineer" };
    std::string nationality_ { "Ukrainian" };
    int age_ { 29 };
};

void testHuman() {
    Human human;

    std::cout << "Human's name is " << human.getName() << std::endl;
    std::cout << "Human's age is " << human.getAge() << std::endl;
    std::cout << "Human's size is " << human.getSize() << std::endl;
    std::cout << "Human has " << human.getnumberOfEyes() << " eyes" << std::endl;
    std::cout << "Human's age is " << human.getAge() << std::endl;
    std::cout << "Human's nationality is " << human.getNationality() << std::endl;
    std::cout << "Human's job is " << human.getJob() << std::endl;
    std::cout << std::endl;
    human.setAge( 35 );
    human.setName( "Mike" );
    human.setSize( 192.8 );
    human.setNationality( "American" );
    human.setJob( "Programmer" );

    std::cout << "Human's name is " << human.getName() << std::endl;
    std::cout << "Human's age is " << human.getAge() << std::endl;
    std::cout << "Human's size is " << human.getSize() << std::endl;
    std::cout << "Human has " << human.getnumberOfEyes() << " eyes" << std::endl;
    std::cout << "Human's age is " << human.getAge() << std::endl;
    std::cout << "Human's nationality is " << human.getNationality() << std::endl;
    std::cout << "Human's job is " << human.getJob() << std::endl;
    std::cout << std::endl;
}

void bacteriumVariant() {
    int choise { rand() % 10 };

    Bacterium bacterium;

    enum DangerousBacterium {
        ClostridiumBotulinum,
        EscherichiaColi,
        VibrioCholerae,
        ClostridiumTetani,
        AspergillusFumigatus,
        Staphylococcus,
        TreponemaPallidum,
        Streptococcus,
        MycobacteriumTuberculosis,
        Listeria
    };

    std::map <DangerousBacterium, std::string> dangerousBacterium { {ClostridiumBotulinum, "Clostridium botulinum"},
                                                                    {EscherichiaColi, "Escherichia coli"},
                                                                    {VibrioCholerae, "Vibrio cholerae"},
                                                                    {ClostridiumTetani, "Clostridium tetani"},
                                                                    {AspergillusFumigatus, "Aspergillus fumigatus"},
                                                                    {Staphylococcus, "Staphylococcus"},
                                                                    {TreponemaPallidum, "Treponema pallidum"},
                                                                    {Streptococcus, "Streptococcus"},
                                                                    {MycobacteriumTuberculosis, "Mycobacterium tuberculosis"},
                                                                    {Listeria, "Listeria"} };

    auto it = dangerousBacterium.find( static_cast< DangerousBacterium > ( choise ) );
    bacterium.setName( it->second );
    std::cout << "I think that " << bacterium.getName() << " is a most dangerous bacterium" << std::endl;
}

void insectVariant() {
    int choise { rand() % 10 };

    Insect insect;

    enum PetsInsects {
        StickInsect,
        Mantis,
        Bug,
        Ant,
        Locust,
        Cricket,
        Spider,
        Silkworm,
        Butterfly,
        Bee
    };

    std::map <PetsInsects, std::string> petsInsects { {StickInsect, "Stick insect"},
                                                      {Mantis, "Mantis"},
                                                      {Bug, "Bug"},
                                                      {Ant, "Ant"},
                                                      {Locust, "Locust"},
                                                      {Cricket, "Cricket"},
                                                      {Spider, "Spider"},
                                                      {Silkworm, "Silkworm"},
                                                      {Butterfly, "Butterfly"},
                                                      {Bee, "Bee"} };

    auto it = petsInsects.find( static_cast< PetsInsects > ( choise ) );
    insect.setName( it->second );
    std::cout << "I think that " << insect.getName() << " is the best choice as an insect pet" << std::endl;
}

void humanVariant() {
    int choise { rand() % 10 };

    Human human;

    enum HumanJobs {
        Programmer,
        Builder,
        Designer,
        HR,
        Driver,
        Lawyer,
        Judge,
        Electrician,
        Teacher,
        Journalist
    };

    std::map <HumanJobs, std::string> humanJobs { {Programmer, "Programmer"},
                                                  {Builder, "Builder"},
                                                  {Designer, "Designer"},
                                                  {HR, "HR"},
                                                  {Driver, "Driver"},
                                                  {Lawyer, "Lawyer"},
                                                  {Judge, "Judge"},
                                                  {Electrician, "Electrician"},
                                                  {Teacher, "Teacher"},
                                                  {Journalist, "Journalist"} };

    auto it = humanJobs.find( static_cast< HumanJobs > ( choise ) );
    human.setJob( it->second );
    std::cout << "I think that " << human.getJob() << " is the most promising job today" << std::endl;
}

void artificialIntelligence() {
    std::string introductoryQuestion { "What question do you want to ask to AI? Enter the appropriate number" };
    std::string bacteriumQuestion { "What do you think is the most dangerous bacterium for humans?" };
    std::string insectsQuestion { "What insect would you recommend to keep as a pet?" };
    std::string jobQuestion { "What is the most promising job?" };
    std::string exitMessage { "If you want to exit" };
    int choiseAI {};

    do {
        std::cout << introductoryQuestion << std::endl;
        std::cout << "1 - " << bacteriumQuestion << std::endl;
        std::cout << "2 - " << insectsQuestion << std::endl;
        std::cout << "3 - " << jobQuestion << std::endl;
        std::cout << "4 - " << exitMessage << std::endl;
        std::cout << "You choise: ";

        std::cin >> choiseAI;
        std::cout << std::endl;
        std::cout << "AI answer: " << std::endl;

        switch( choiseAI ) {
            case 1:
                bacteriumVariant();
                break;
            case 2:
                insectVariant();
                break;
            case 3:
                humanVariant();
                break;
            case 4:
                std::cout << "Have a nice day!";
                break;
            default:
                std::cout << "You ented wrong symbol! Please, try again!" << std::endl;
                break;
        }
        std::cout << std::endl;

    } while( choiseAI != 4 );

}

int main() {
    srand( time( nullptr ) );
    testHuman();
    artificialIntelligence();
}
