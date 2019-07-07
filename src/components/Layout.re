module Header = {
  [@react.component]
  let make = () => {
    <header className="p-4 md:px-0 md:h-24 border-b md:flex items-center">
      <div
        className="max-w-6xl w-full mx-auto md:flex items-center justify-between
        text-gray-700 font-semibold text-lg">
        <div> "Teamfight Tactics"->React.string </div>
        <nav className="flex flex-1 mt-4 md:mt-0 md:justify-end">
          <Router.NavLink
            activeClassName="text-pink-500" className="" href="/">
            "Items"->React.string
          </Router.NavLink>
          <Router.NavLink
            activeClassName="text-pink-500" className="ml-6" href="/champions">
            "Champions"->React.string
          </Router.NavLink>
          <a
            ariaLabel="Go to GitHub project"
            className="ml-6"
            href="https://github.com/believer/teamfight-tactics-cheat-sheet">
            <Icons.GitHub />
          </a>
        </nav>
      </div>
    </header>;
  };
};

module Main = {
  [@react.component]
  let make = (~children) => {
    <main className="w-full max-w-6xl mx-auto mt-4 md:mt-24 md:flex">
      children
    </main>;
  };
};
