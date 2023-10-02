/**
 * Component Variants
 *
 * This code pattern helps you creating component variants
 * dependent on styles only.
 */



/**
 * Define variants or tailwind classes as
 * various properties of an object named
 * "className" specifically.
*/
const className = {
	base: "h-10 bg-purple-700 text-white",
	error: "h-10 bg-red-500 text-white border-2 border-red-700",
};


/**
 * Add conditional logic to apply variants in your
 * component.
 */
const MyComponent = (error) => (
	<button className={error ? className.error : className.base}>Submit</button>
);
