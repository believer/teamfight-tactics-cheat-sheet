[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  <>
    <Layout.Header />
    <Layout.Main>
      {switch (url.path) {
       | [] => <PageItems />
       | ["champions"] => <PageChampions />
       | _ => <NotFound />
       }}
    </Layout.Main>
  </>;
};
