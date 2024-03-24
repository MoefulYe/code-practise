/// url = https://tsch.js.org/898/play

// type Includes<T extends readonly any[], U> = {
//   [P in T[number]]: true
// }[U] extends true ? true : false;

type ExclusiveOr<X, Y> = Exclude<X, Y> | Exclude<Y, X>;

// export type Equal<X, Y> =
//   (<T>() => T extends X ? 1 : 2) extends
//   (<T>() => T extends Y ? 1 : 2) ? true : false
type Equal<X, Y> = ExclusiveOr<X, Y> extends never ? true : false;

type Includes<T extends readonly any[], U> = T extends [infer P, ...infer R]
  ? Equal<P, U> extends true
    ? true
    : Includes<R, U>
  : false;
