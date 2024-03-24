/// url = https://tsch.js.org/8/play

// type MyExclude<T, U> = T extends U ? never : T;

// type MyReadonly<Record, ReadOnlyKeys extends keyof Record = keyof Record> = {
//   readonly [Key in ReadOnlyKeys]: Record[Key];
// } & {
//   [Key in MyExclude<keyof Record, ReadOnlyKeys>]: Record[Key];
// };

type MyReadonly2<Record, ReadonlyKeys extends keyof Record = keyof Record> = {
  readonly [ReadonlyKey in ReadonlyKeys]: Record[ReadonlyKey];
} & {
  [Key in keyof Record as Key extends ReadonlyKeys ? never : Key]: Record[Key];
};