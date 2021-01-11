#ifndef GAME_TIME_H
#define GAME_TIME_H

class GameTime
{
  int Hour;
  int Minutes;

  unsigned int Timestamp;

public:
  int GetHour() { return Hour; }
  int GetMinutes() { return Minutes; }
  unsigned int GetTimestamp() { return Timestamp; }

  GameTime(int hour, int minutes);

  void Set(int hour, int minutes);
  void Set(unsigned int timestamp);
  void Update(float elapsed);
};

#endif