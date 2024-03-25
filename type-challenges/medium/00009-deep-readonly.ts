/// url = https://tsch.js.org/9/play

type Prim = undefined | null | boolean | string | number | Function

type DeepReadonly<T> = T extends Prim ? T : {
  readonly [Key in keyof T]: DeepReadonly<T[Key]>;
}