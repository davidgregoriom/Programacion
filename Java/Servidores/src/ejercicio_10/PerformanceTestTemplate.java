package ejercicio_10;

import java.util.ArrayList;
import java.util.List;

public abstract class PerformanceTestTemplate {

  protected abstract int getWarmUpIterationNum();

  protected abstract int getIterationNum();

  protected abstract void iteration();

  public void run() {
    for (int idx = 0; idx < getWarmUpIterationNum(); idx++) {
      iteration();
    }

    final List<Long> iterationsExecutionTimes = new ArrayList<>();
    for (int idx = 0; idx < getIterationNum(); idx++) {
      final long start = System.currentTimeMillis();
      iteration();
      final long end = System.currentTimeMillis();
      iterationsExecutionTimes.add(end - start);
    }

    final double avg = iterationsExecutionTimes.stream()
        .mapToDouble(x -> x).sum() / getIterationNum();

    System.out.println("Avg time per iteration: " + avg);
  }
}