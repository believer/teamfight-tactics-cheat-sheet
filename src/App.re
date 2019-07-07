type state = Items.t;

type action =
  | UpdateItem(Items.t);

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | UpdateItem(itemType) => itemType
        },
      `BFSword,
    );

  <>
    <header className="py-4 bg-indigo-200">
      <div className="mx-auto w-3/5">
        "Teamfight Tactics cheat sheet"->React.string
      </div>
    </header>
    <main className="w-3/5 mx-auto mt-24 flex">
      <div className="mr-10 w-1/4">
        {Items.base
         ->Belt.List.map(((name, itemType, effect)) =>
             <button
               className={Cn.make([
                 "block font-semibold text-gray-500 text-left mb-2",
                 "text-gray-900"->Cn.ifTrue(itemType === state),
               ])}
               key=name
               onClick={_ => dispatch(UpdateItem(itemType))}>
               name->React.string
               {switch (effect) {
                | Some(e) =>
                  <span className="block text-xs text-gray-600">
                    e->React.string
                  </span>
                | None => React.null
                }}
             </button>
           )
         ->Belt.List.toArray
         ->React.array}
      </div>
      <div className="flex-1">
        {Items.fromType(state)
         ->Belt.List.map(({name, description, item}) =>
             <div className="mb-4" key=name>
               <div className="font-semibold"> name->React.string </div>
               <div className="text-gray-800 text-sm">
                 description->React.string
               </div>
               <div className="text-gray-600 text-xs">
                 {state->Items.name
                  ++ " + "
                  ++ item->Items.name
                  |> React.string}
               </div>
             </div>
           )
         ->Belt.List.toArray
         ->React.array}
      </div>
    </main>
  </>;
};
