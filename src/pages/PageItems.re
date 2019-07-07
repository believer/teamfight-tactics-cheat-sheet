type state = Items.item;

type action =
  | UpdateItem(Items.item);

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
    <div
      className="px-4 pb-4 mb-4 md:px-0 md:mr-10 md:w-1/4 border-b
    md:border-b-0">
      {Items.base
       ->Belt.List.map(({name, item, description}) =>
           <button
             className={Cn.make([
               "block font-semibold text-left mb-2",
               "text-pink-500"->Cn.ifTrue(item === state),
             ])}
             key=name
             onClick={_ => dispatch(UpdateItem(item))}>
             name->React.string
             <span className="block text-xs font-normal text-gray-700">
               description->React.string
             </span>
           </button>
         )
       ->Belt.List.toArray
       ->React.array}
    </div>
    <div className="px-4 md:px-0 flex-1">
      {Items.fromType(state)
       ->Belt.List.map(({name, description, item}) =>
           <div className="mb-4" key=name>
             <div className="font-semibold"> name->React.string </div>
             <div className="text-gray-800 text-sm">
               description->React.string
             </div>
             <div className="text-gray-600 text-xs">
               {state->Items.Item.name
                ++ " + "
                ++ item->Items.Item.name
                |> React.string}
             </div>
           </div>
         )
       ->Belt.List.toArray
       ->React.array}
    </div>
  </>;
};
