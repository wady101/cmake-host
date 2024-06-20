#ifndef STATE_HPP
#define STATE_HPP

#include <memory>
#include <iostream>

class State{
    public:
        State() = default;
    virtual std::unique_ptr<State> onRecord() {return nullptr;};
    virtual std::unique_ptr<State> onPlay() {return nullptr;}; 
    virtual std::unique_ptr<State> onStop() {return nullptr;}; 
    protected:
    std::unique_ptr<State> noTransistion() {return nullptr;}
    template <typename State_Ty>
    std::unique_ptr<State> toTransistion() {
        return std::make_unique<State_Ty>();
    }
};
class Event{};

class Record;
class Play;
class Ready;
class Record : public State 
{ // each class is a state
    public:
        std::unique_ptr<State> initialise()
        {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            return std::make_unique<Record>();
        }
        std::unique_ptr<State> onRecord() override {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            return initialise();
        }
        std::unique_ptr<State> onPlay() override {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            return noTransistion();
        }
        std::unique_ptr<State> onStop() override {
            // return std::make_unique<Ready>();
            // pointless to use this as forward declaration does not bring the inherited class with it
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            return toTransistion<Ready>();
        }
};
class Ready : public State 
{
    public:
        std::unique_ptr<State> initialise()
        {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            return std::make_unique<Ready>();
        }
        std::unique_ptr<State> onRecord() override {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            return initialise();
        }
        std::unique_ptr<State> onPlay() override {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            return toTransistion<Play>();
        }
        std::unique_ptr<State> onStop() override {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            return noTransistion();
        }
};
class Play : public State 
{
    public:
        std::unique_ptr<State> initialise()
        {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            return std::make_unique<Play>();
        }
        std::unique_ptr<State> onRecord() override {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            return noTransistion();
        }
        std::unique_ptr<State> onPlay() override {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            return initialise();
        }
        std::unique_ptr<State> onStop() override {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            return toTransistion<Ready>();
        }

};
        
class Sequencer 
{
    public:
        Sequencer() {
            current_state = std::make_unique<Play>(); // random
        }
        void play() {
            if (auto new_state = current_state->onPlay())
                current_state = std::move(new_state);
        }
        void stop() {
            if (auto new_state = current_state->onStop())
                current_state = std::move(new_state);
        }
        void record() {
            if (auto new_state = current_state->onRecord())
                current_state = std::move(new_state);
        }
    private:
        std::unique_ptr<State> current_state;
};
    

#endif /* STATE_HPP */
