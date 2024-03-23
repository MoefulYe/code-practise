/// url = https://tsch.js.org/898/play

type Include<T extends readonly unknown[], U> = T extends [infer P, ...infer R]
  ? U extends P
    ? true
    : Include<R, U>
  : false;
