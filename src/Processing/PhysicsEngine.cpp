#include "Processing/PhysicsEngine.hpp"
//CONSTRUCTORS
PhysicsEngine::PhysicsEngine()
{
    dLink->runPhysics = true;
    frametime = 0.0f;
    PI = 3.1415926535897932384626433832795028841971693993751f;
    G = 6.67e-11;
}
//DESTRUCTORS

//METHODS

void PhysicsEngine::Run()
{
    GMutex.lock();
    LOG::console("[Physics][Info] Thread launched");
    GMutex.unlock();
    sf::Clock limit;
    limit.restart();
    while (dLink->runPhysics)
    {
        while(dLink->debug.tPhysSleep.size() > dLink->settings.threadMeanAmount)
        {
            dLink->debug.tPhysSleep.pop_front();
        }
        if(limit.getElapsedTime().asSeconds() < 1.0/pLimit)
        {
            dLink->debug.tPhysSleep.push_back((1.0/pLimit - limit.getElapsedTime().asSeconds())*1000);
            sf::sleep(sf::seconds(1.0/pLimit - limit.getElapsedTime().asSeconds()));
        }
        else
        {
            dLink->debug.tPhysSleep.push_back(0.0);
        }
        frametime = limit.restart().asSeconds();
        GMutex.lock();
        for (std::list<SpaceObject>::iterator it = dLink->level.activeSystem.SpaceObjectList.begin(); it != dLink->level.activeSystem.SpaceObjectList.end(); it++)
        {
            if(it->flyByLocal) // input forces
            {
                Vector seperation = dLink->localCtrl.targetPoint - it->Position;
                if(seperation.x != 0)
                    it->Rotation = atan(seperation.y/seperation.x) + PI/2.0;
                if(seperation.x < 0)
                {
                    it->Rotation += PI;
                }

                Vector forw(cos(it->Rotation - PI/2.0),sin(it->Rotation - PI/2.0));
                forw = forw * dLink->localCtrl.translateForward;
                forw = forw * frametime;
                it->Velocity = it->Velocity + forw;
            }
            it->Position = it->Position + (it->Velocity * frametime);
        }

        GMutex.unlock();
    }
    LOG::console("[Physics][Info] Thread stopped");
}
void PhysicsEngine::Stop()
{
    dLink->runPhysics = false;
}