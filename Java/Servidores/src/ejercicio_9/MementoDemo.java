package ejercicio_9;

public class MementoDemo {
	  public static void main(String[] args) {
	    final EditorText editorText = new EditorText();
	    final EditorTextMementoManager mementoManager = new EditorTextMementoManager();
	    mementoManager.save(new EditorTextMemento(editorText));

	    editorText.addText("This is first line");
	    mementoManager.save(new EditorTextMemento(editorText));

	    editorText.addText("\nThis is second line");
	    mementoManager.save(new EditorTextMemento(editorText));

	    editorText.addText("\nThis is third line");
	    mementoManager.save(new EditorTextMemento(editorText));

	    editorText.addText(" This is second part of 3rd line");
	    mementoManager.save(new EditorTextMemento(editorText));

	    System.out.println(editorText.getValue());
	    System.out.println();

	    mementoManager.restore();
	    mementoManager.restore();
	    editorText.restoreFromMemento(mementoManager.restore());
	    System.out.println(editorText.getValue());

	  }
	}