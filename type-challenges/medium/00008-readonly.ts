/// url = https://tsch.js.org/8/play

type MyReadOnly<Record, ReadOnlyKeys extends keyof Record> = {
  [Key in keyof Record]: Key extends ReadOnlyKeys ? Readonly<Record[Key]> : Record[Key]
}