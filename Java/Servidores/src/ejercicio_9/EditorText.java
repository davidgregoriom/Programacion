package ejercicio_9;

public class EditorText {
	  private String value = "";

	  public void addText(final String textToAdd) {
	    value += textToAdd;
	  }

	  public String getValue() {
	    return value;
	  }

	  public void restoreFromMemento(final EditorTextMemento memento) {
	    value = memento.getValue();
	  }
	}