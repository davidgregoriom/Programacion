package ejercicio_10;

import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class SortingPerformanceTest extends PerformanceTestTemplate {
  @Override
  protected int getWarmUpIterationNum() {
    return 2;
  }

  @Override
  protected int getIterationNum() {
    return 100;
  }

  @Override
  protected void iteration() {
    final List<Long> longs = Stream.generate(() -> new Random().nextLong())
        .limit(10000).collect(Collectors.toList());
    final List<Long> sortedValues = longs.stream()
        .sorted()
        .collect(Collectors.toList());
  }
}