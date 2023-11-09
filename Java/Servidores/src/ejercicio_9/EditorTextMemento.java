package ejercicio_9;

public class EditorTextMemento {

	  private final String value;

	  public EditorTextMemento(final EditorText editorText) {
	    value = editorText.getValue();
	  }

	  public String getValue() {
	    return value;
	  }
	}