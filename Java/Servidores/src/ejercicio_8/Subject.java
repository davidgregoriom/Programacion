package ejercicio_8;

import java.util.ArrayList;
import java.util.List;

public class Subject {
  private final List<Observer> observers;
  private int state = 0;

  public Subject() {
    observers = new ArrayList<>();
  }

  public void subscribe(final Observer observer) {
    if (!observers.contains(observer)) {
      observers.add(observer);
    }
  }

  public void changeStateBy(final int change) {
    state += change;
    observers.forEach(Observer::update);
  }

  public int getState() {
    return state;
  }
}