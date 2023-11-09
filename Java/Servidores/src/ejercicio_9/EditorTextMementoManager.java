package ejercicio_9;

import java.util.ArrayDeque;
import java.util.Deque;

public class EditorTextMementoManager {

  private final Deque<EditorTextMemento> mementos = new ArrayDeque<>();

  public void save(final EditorTextMemento memento) {
    mementos.push(memento);
  }
  public EditorTextMemento restore() {
    return mementos.pop();
  }
}