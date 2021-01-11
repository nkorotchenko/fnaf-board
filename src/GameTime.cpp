#include "GameTime.h"

GameTime::GameTime(int hour, int minutes)
{
  Set(hour, minutes);
}

void GameTime::Set(int hour, int minutes)
{
  Set((hour * 60000) + (minutes * 1000));
}

void GameTime::Set(unsigned int timestamp)
{
  Timestamp = timestamp;

  if (Timestamp >= (24 * 60000))
  {
    Timestamp = 0;
  }

  Hour = (Timestamp / 60000) % 24;
  Minutes = (Timestamp / 1000) % 60;  
}

void GameTime::Update(float elapsed)
{
  int timestampElapsed = int(1000 * elapsed);
  
  Set(Timestamp + timestampElapsed);
}